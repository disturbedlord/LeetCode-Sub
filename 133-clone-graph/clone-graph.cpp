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
        if(node == NULL) return NULL;
        Node* prev = new Node(node->val);
        Node* res = DFS(node , prev);
        return res;
        
    }
};