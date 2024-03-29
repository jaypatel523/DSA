// leetcode problem link : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> ans;

        // store vertical, level, multiple nodes 
        map<int, map<int, multiset<int>>> nodes;

        // to do level order traversal 
        // node, vertical, level 
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}}); 



        while(!q.empty()) {

            auto p = q.front();
            q.pop();
            TreeNode * node = p.first;
            int vertical = p.second.first;
            int level = p.second.second;

            nodes[vertical][level].insert(node->val);

            if(node->left) {
                q.push({node->left, {vertical - 1, level + 1}});
            }

            if(node->right) {
                q.push({node->right, {vertical + 1, level + 1}});
            }
        }


        for(auto i : nodes) {
            vector<int> everyVertical;
            for(auto j : i.second){
                everyVertical.insert(everyVertical.end(), j.second.begin(), j.second.end());
            }

            ans.push_back(everyVertical);
        }

        return ans;



        
    }
};
