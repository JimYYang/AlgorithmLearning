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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) pos[inorder[i]] = i;

        return build(inorder, postorder, 0, n - 1, 0, n - 1);
    }

    TreeNode* build(vector<int> &inorder, vector<int> &postorder, int il, int ir, int pl, int pr)
    {
        if (pl > pr) return nullptr;

        int val = postorder[pr];
        TreeNode *root = new TreeNode(val);
        int k = pos[val];

        root->left = build(inorder, postorder, il, k - 1, pl, pl - il + k - 1);
        root->right = build(inorder, postorder, k + 1, ir, pl - il + k, pr - 1);
        return root;
    }
};
