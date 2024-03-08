/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // 图的遍历需要单独判重
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {

        if (!node) return node;

        dfs(node);

        for (auto &[src, dst] : mp)
        {
            for (auto &edge : src->neighbors)
                dst->neighbors.push_back(mp[edge]);
        }
        return mp[node];
    }

    void dfs(Node *node)
    {
        if (!node) return;

        mp[node] = new Node(node->val);

        for (auto &edge : node->neighbors)
            if (mp.count(edge) == 0)
                dfs(edge);
    }
};
