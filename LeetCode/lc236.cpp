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
        // 如果以root为根的子树 包含p和q，返回LCA
        // 如果只包含p, 返回p
        // 如果只包含q, 返回q
        // 如果都不包含, 返回nullptr

        if (!root || root == p || root == q) return root;
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        // 1. 如果左边为空, 那么右边： 
        // a. 右边包含p,q 则右边是正确的LCA
        // b. 右边只包含一个, 则返回p或q
        // c. 右边都不包含, 返回nullptr
        // 所以如果左边为空，都是返回right
        if (!left) return right;
        if (!right) return left;
        return root;
    }
};