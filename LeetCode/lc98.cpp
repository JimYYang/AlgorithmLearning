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
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
    
    bool dfs(TreeNode *root, long left_val, long right_val)
    {
        if (!root) return true;
        if (left_val >= root->val || root->val >= right_val)
            return false;
        return dfs(root->left, left_val, root->val) && dfs(root->right, root->val, right_val);
    }
};
