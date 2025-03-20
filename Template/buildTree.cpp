#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

struct TreeNode
{
    int val{0};
    TreeNode *left{nullptr}, *right{nullptr};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *buildTree(const vector<string> &nodes)
{
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode *root = new TreeNode(stoi(nodes[0]));

    queue<TreeNode*> que;
    que.push(root);

    int i = 1, n = nodes.size();
    while (!que.empty() && i < n)
    {
        TreeNode *cur = que.front();
        que.pop();
        if (i < n && nodes[i] != "null")
        {
            cur->left = new TreeNode(stoi(nodes[i]));
            que.push(cur->left);
        }
        i++;
        if (i < n && nodes[i] != "null")
        {
            cur->right = new TreeNode(stoi(nodes[i]));
            que.push(cur->right);
        }
        i++;
    }
    return root;
}

int ans;
unordered_map<long long, int>cnt;

void dfs(TreeNode *root, int sum, long long curSum)
{
    if (!root) return;
    curSum += root->val;
    ans += cnt[curSum - sum];
    cnt[curSum]++;
    dfs(root->left, sum, curSum);
    dfs(root->right, sum, curSum);
    cnt[curSum]--;
}

int pathSum(TreeNode* root, int targetSum) {
    cnt[0]++;
    dfs(root, targetSum, 0);
    return ans;
}


int main()
{
    vector<string> nodes{"10","5","-3","3","2","null","11","3","-2","null","1"};
    int targetSum = 8;
    TreeNode *root = buildTree(nodes);
    int res = pathSum(root, targetSum);
    cout << res << endl;
}