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
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        // 遍历图可能会有环，需要判重一下
        // 深拷贝问题，原点到新点的映射
        unordered_map<Node*, Node*> hash;
        function<void(Node*)> dfs = [&](Node *node) -> void {
            hash[node] = new Node(node->val);

            for (auto &ver : node->neighbors)
            {
                if (hash.count(ver) == 0)
                    dfs(ver);
            }
        };

        dfs(node); // 复制所有点

        for (auto &[src, dst] : hash)
        {
            for (auto &ver : src->neighbors)
            {
                dst->neighbors.push_back(hash[ver]);
            }
        }

        return hash[node];
    }
};