// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         return dfs(root, LONG_MIN, LONG_MAX);
//     }
    
//     bool dfs(TreeNode *root, long left_val, long right_val)
//     {
//         if (!root) return true;
//         if (left_val >= root->val || root->val >= right_val)
//             return false;
//         return dfs(root->left, left_val, root->val) && dfs(root->right, root->val, right_val);
//     }
// };

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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return dfs(root)[0];
    }
    
    vector<int> dfs(TreeNode *root)
    {
        vector<int> res{1, root->val, root->val};
        if (root->left)
        {
            auto left = dfs(root->left);
            if (left[0] == 0 || left[2] >= res[2]) res[0] = 0;
            res[1] = min(res[1], left[1]);
            res[2] = max(res[2], left[2]);
        }
        if (root->right)
        {
            auto right = dfs(root->right);
            if (right[0] == 0 || right[1] <= res[2]) res[0] = 0;
            res[1] = min(res[1], right[1]);
            res[2] = max(res[2], right[2]);
        }
        return res;
    }
};
