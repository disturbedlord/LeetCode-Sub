/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    //TC : O(n)
    //SC : O(n + n) ~ O(n) recursion will take extra n space 
    /*Idea : Use Depth First Search (Keep navigating the child, then go for sibling) to get each node
    if the node was already processed, get it from memory (using dict) else do DFS on the node
    */
    unordered_map<int,Node*> seen;
    Node* DFS(Node* node , Node* prev){
        if(node == NULL) return node;
        Node* root = new Node(node->val);
        seen[root->val] = root;
        for(auto n : node->neighbors){

            if(seen.find(n->val) == seen.end()){
                root->neighbors.push_back(DFS(n , root));
            }else{
                root->neighbors.push_back(seen[n->val]);
            }
        }
        return root;
    }

    Node* cloneGraph(Node* node) {
        // if(node == NULL) return NULL;
        // Node* prev = new Node(node->val);
        // Node* res = DFS(node , prev);
        // return res;
        
        //Using Queue
        if(node == NULL) return NULL;
        unordered_map<int,Node*> memo;

        queue<Node*> queue;
        Node* root = new Node(node->val);
        queue.push(node); //ori
        queue.push(root); //clone

        vector<Node*> test;
        while(!queue.empty()){
            auto ori = queue.front();
            queue.pop();
            auto clone = queue.front();
            queue.pop();
            
            // cout<<ori<<" "<<clone<<" ";
            
            if(memo.find(ori->val) == memo.end()) memo[clone->val] = clone;
            
            test.push_back(clone);
            for(auto child : ori->neighbors){
                // cout<<child->val<<" ";
                if(memo.find(child->val) == memo.end()){
                    //auto ch = new Node(child->val);
                    auto cl = new Node(child->val);
                    clone->neighbors.push_back(cl);
                    queue.push(child);
                    queue.push(cl);
                    memo[cl->val] = cl;
                }else{
                    clone->neighbors.push_back(memo[child->val]);
                }
            }
            //cout<<endl;
        }
    // cout<<endl;
    //     for(auto x : memo) {cout<<x.second->val<<" : "; for(auto y : x.second->neighbors) cout<<y->val<<" ";cout<<endl;}

    //     for(auto x : test){
    //         cout<<x->val<<" ";
    //         for(auto y : x->neighbors){
    //             cout<<y->val<< " ";
    //         }
    //         cout<<endl;
    //     }
        return root;
    }
};