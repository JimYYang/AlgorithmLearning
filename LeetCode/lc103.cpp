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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        if (root) que.push(root);

        bool inver = false;

        while (que.size())
        {
            vector<int> level;
            int len = que.size();
            
            for (int i = 0; i < len; i++)
            {
                auto cur = que.front();
                que.pop();
                level.push_back(cur->val);
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            if (inver)
            {
                reverse(level.begin(), level.end());
            }
            ans.push_back(std::move(level));
            inver = !inver;
        }
        return ans;
    }
};
