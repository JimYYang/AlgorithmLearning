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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> que;
        if (root) que.push(root);

        while (que.size())
        {
            double sum = 0;
            int len = que.size();
            for (int i = 0; i < len; i++)
            {
                auto cur = que.front();
                que.pop();
                sum += cur->val;
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            ans.push_back(sum / len);
        }
        return ans;
    }
};
