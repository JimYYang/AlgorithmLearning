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
    int ans = INT_MAX;
    bool is_first = true;
    int last;
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return ans;
    }

    void dfs(TreeNode *root)
    {
        if (!root) return;
        dfs(root->left);

        if (is_first) is_first = false;
        else
        {
            ans = min(ans, root->val - last);
        }
        last = root->val;

        dfs(root->right);
    }
};
