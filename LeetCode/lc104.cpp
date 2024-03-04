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
    int dfs(TreeNode *cur, int depth)
    {
        if (cur == nullptr)
            return depth;
        depth++;
        return max(dfs(cur->left, depth), dfs(cur->right, depth));
    }
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        return dfs(root, 0);
    }
};
