/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 以root为根的子树，如果包含LCA，返回LCA,如果只包含p返回p,如果只包含q，返回q
        if (!root || root == p || root == q) return root;
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if (!left) return right;
        if (!right) return left;
        // 都不空 说明一边一个  说明当前root就是LCA
        return root;
    }
};