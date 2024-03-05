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
    int ans = 0;
    int sumNumbers(TreeNode* root) {
        if (root) dfs(root, 0);
        return ans;
    }
    
    void dfs(TreeNode *root, int sum)
    {
        sum = sum * 10 + root->val;

        if (!root->left && !root->right)
        {
            ans += sum;
        }
        else
        {
            if (root->left) dfs(root->left, sum);
            if (root->right) dfs(root->right, sum);
        }
    }
};
