// leetcode problem link : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        queue<TreeNode*> q;
        vector<vector<int>>ans;
        if(!root) return {};
        q.push(root);

        bool isLtoR = true;
         

        while(!q.empty()){
            vector<int>level;
            int size=q.size();

             for(int i=0; i<size; i++){
                 TreeNode* n=q.front();
                 q.pop();
    
                 if(n->left) q.push(n->left);
                 if(n->right) q.push(n->right);
                 level.push_back(n->val);
             }

             if(!isLtoR) reverse(level.begin(), level.end());

             ans.push_back(level);
             isLtoR = !isLtoR;

         }


         return ans;

        
    }
};
