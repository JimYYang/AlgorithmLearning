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
    unordered_map<int, int> pos;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) pos[inorder[i]] = i;
        return build(preorder, inorder, 0, inorder.size() - 1, 0, preorder.size() - 1);
    }

    TreeNode* build(vector<int> &preorder, vector<int> &inorder, int pl, int pr, int il, int ir)
    {
        if (pl > pr) return nullptr;
        
        int val = preorder[pl];
        TreeNode *root = new TreeNode(val);

        int k = pos[val];

        root->left = build(preorder, inorder, pl + 1, pl + k - il, il, k - 1);
        root->right = build(preorder, inorder, pl + k -il + 1, pr, k + 1, ir);
        return root;
    }
};
