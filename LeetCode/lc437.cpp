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
    unordered_map<long long, int> cnt;
    int res = 0;
    int pathSum(TreeNode* root, int targetSum) {
        // 注意这是从上到下的路径  不是任意两个节点的路径
        cnt[0]++;
        dfs(root, targetSum, 0);
        return res;
    }

    void dfs(TreeNode *root, int sum, long long curSum)
    {
        if (!root) return;
        curSum += root->val;
        res += cnt[curSum - sum];
        cnt[curSum]++;
        dfs(root->left, sum, curSum);
        dfs(root->right, sum, curSum);
        cnt[curSum]--;
    }
};
