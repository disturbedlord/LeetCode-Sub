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
    unordered_map<int,Node*> seen;
    Node* clone(Node* node , Node* prev){
        if(node == NULL) return node;
        //cout<<node->val<<endl;
        Node* root = new Node(node->val);
        seen[root->val] = root;
        for(auto n : node->neighbors){
            if(prev != NULL && prev->val == n->val) root->neighbors.push_back(seen[prev->val]);
            if(prev != NULL && prev->val != n->val) {
                if(seen.find(n->val) != seen.end())
                    root->neighbors.push_back(seen[n->val]);
                else root->neighbors.push_back(clone(n , node));
            }
        }
        //cout<<"Root : "<<root->val<<endl;
        return root;
    }

    Node* cloneGraph(Node* node) {
        //cout<<node<<endl;
        if(node == NULL) return NULL;
        Node* prev = new Node(node->val);
        Node* res = clone(node , prev);
               // for(auto x : node->neighbors) cout<<x<<endl;

        //for(auto x : res->neighbors) cout<<x->val<<" : "<<x<<endl;
        return res;
        
    }
};