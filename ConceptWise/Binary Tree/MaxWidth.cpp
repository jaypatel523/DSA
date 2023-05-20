// leetcode problem link : https://leetcode.com/problems/maximum-width-of-binary-tree/description/

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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root == NULL) return 0;

        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        int maxWidth = 1;


        while(!q.empty()) {

            int levelsize = q.size();
            int rootIndex = q.front().second;


            int first, last;
            for(int i=0; i<levelsize; i++) {

                TreeNode * node = q.front().first;
                int childIndex = q.front().second - rootIndex;
                q.pop();

                if(i == 0) first = childIndex;
                if(i == levelsize - 1) last = childIndex;

                if(node->left) q.push({node->left, (long long)2*childIndex + 1});
                if(node->right) q.push({node->right, (long long)2*childIndex + 2});

            }
            maxWidth = max(maxWidth, last - first + 1);

        }


        return maxWidth;
        

    }
};
