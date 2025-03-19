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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++)
            pos[inorder[i]] = i;
        
        function<TreeNode*(int, int, int, int)> build = [&](int pl, int pr, int il, int ir) -> TreeNode* {
            if (pl > pr) return nullptr;

            int rootVal = preorder[pl];

            int k = pos[rootVal];
            TreeNode *root = new TreeNode(rootVal);

            root->left = build(pl + 1, pl + k - il, il, k - 1);
            root->right = build(pl + k - il + 1, pr, k + 1, ir);
            return root;
        };
        return build(0, n - 1, 0, n - 1);
    }
};