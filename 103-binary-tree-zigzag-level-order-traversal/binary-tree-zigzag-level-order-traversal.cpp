/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 typedef vector<vector<int>> Result;
class Solution {
public:
    Result zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        Result result = Result();
        queue<pair<TreeNode* , int>> q;
        q.push({root , 0});
        int direction = 0;
        vector<int> l = vector<int>();
        int prev = 0;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            auto node = front.first;
            auto level = front.second;
            if(level == prev){
                l.push_back(node->val);
            }else{
                if(prev % 2 == 1){
                    reverse(l.begin() , l.end());
                }
                result.push_back(l);
                l.clear();
                l.push_back(node->val);
            }

            if(node->left) q.push({node->left , level + 1});
            if(node->right) q.push({node->right , level + 1});
            prev = level;
        }
        if(prev % 2 == 1){
            reverse(l.begin()  , l.end());
        }
        result.push_back(l);
        return result;
    }
};