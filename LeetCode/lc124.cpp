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
    int ans;
    // 枚举路径的最高点
    // dfs返回的是：以这个节点向下走的路径最大值（只能要么左要么右走）
    int dfs(TreeNode *root)
    {
        if (!root) return 0;
        // 用0来代表不选
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));
        ans = max(ans, root->val + left + right);
        // 假设已经求出f(a) f(b)
        // 那么u: 1). vu 2) vu + f(a) 3). vu + f(b).
        // 用0可以很好地求出这三种情况
        return root->val + max(left, right);
    }
    
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }
};