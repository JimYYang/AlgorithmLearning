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
    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res[0], res[1]);
    }

    vector<int> dfs(TreeNode *root)
    {
        if (!root) return {0, 0};

        auto left = dfs(root->left), right = dfs(root->right);
        return {max(left[0], left[1]) + max(right[0], right[1]), left[0] + right[0] + root->val};
    }
};
