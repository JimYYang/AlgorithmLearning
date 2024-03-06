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
        // 以root为根的子树 如果包含p q 则返回他们的LCA
        // 如果只包含p 则返回p
        // 如果只包含q 则返回q
        // 如果都不包含  返回nullptr
        if (!root || root == p || root == q) return root;
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if (!left) return right;
        if (!right) return left;
        return root;
    }
};
