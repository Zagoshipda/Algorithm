/*
    https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/
    (1123. Lowest Common Ancestor of Deepest Leaves)
*/

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
        // (height, node)
        pair<int, TreeNode*> dfs(TreeNode* curr){
            if(curr == nullptr){
                return {0, curr};
            }

            auto [left_height, left] = dfs(curr->left);
            auto [right_height, right] = dfs(curr->right);

            if(left_height > right_height){
                return {left_height + 1, left};
            }
            else if(left_height < right_height){
                return {right_height + 1, right};
            }
            else{
                // choose anyone
                return {left_height + 1, curr};
            }
        }

        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            return dfs(root).second;
        }
    };
