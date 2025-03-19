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
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root) dfs(root, targetSum);
        return ans;
    }

    void dfs(TreeNode *root, int sum)
    {
        if (!root) return;
        path.push_back(root->val);
        sum -= root->val;
        if (!root->left && !root->right)
        {
            if (!sum)
            {
                ans.push_back(path);
            }
        }

        if (root->left) dfs(root->left, sum);
        if (root->right) dfs(root->right, sum);

        // 只有外部变量需要“恢复原状态”
        path.pop_back();
    }
};