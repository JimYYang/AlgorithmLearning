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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inOrder;
        stack<TreeNode*> stk;
        int num = 0;
        while (stk.size() || root)
        {
            while (root)
            {
                stk.push(root);
                root = root->left;
            }

            root = stk.top();
            stk.pop();
            num++;
            if (num == k)
            return root->val;
            root = root->right;
        }
        return -1;
    }
};
