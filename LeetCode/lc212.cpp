class Solution {
public:
    struct Node{
        Node *son[26];
        int id;

        Node()
        {
            for (int i = 0; i < 26; i++) son[i] = nullptr;
            id = -1;
        }
    };
    Node *root;

    void insert(const string &word, int wordId)
    {
        auto p = root;
        for (auto c : word)
        {
            int u = c - 'a';
            if (!p->son[u]) p->son[u] = new Node();
            p = p->son[u];
        }
        p->id = wordId;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Node();

        for (int i = 0; i < words.size(); i++) insert(words[i], i); 

        std::array<int, 4> dx{-1, 0, 1, 0}, dy{0, 1, 0, -1};
        unordered_set<int> ids;
        int n = board.size(), m = board[0].size();
        function<void(Node*, int, int)> dfs = [&](Node *p, int x, int y)->void 
        {
            if (p->id != -1)
            {
                ids.insert(p->id);
                // 这里不能写return  因为可能存在 ab abc的情况 可能还要继续找下去
                // return;
            }

            char ori = board[x][y];
            board[x][y] = '.';

            for (int i = 0; i < 4; i++)
            {
                int a = x + dx[i];
                int b = y + dy[i];
                if (a < 0 || a >= n || b < 0 || b >= m || board[a][b] == '.')
                    continue;
                int u = board[a][b] - 'a';
                if (p->son[u])
                    dfs(p->son[u], a, b);
            }

            board[x][y] = ori;
        };

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int u = board[i][j] - 'a';
                if (root->son[u])
                    dfs(root->son[u], i, j);
            }
        }

        vector<string> res;
        for (auto id : ids) res.push_back(words[id]);
        return res;
    }
};