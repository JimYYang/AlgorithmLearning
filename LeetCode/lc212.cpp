class Solution {
public:
    struct Node{
        Node *son[26];
        int id;
        Node()
        {
            for (int i = 0; i < 26; i++)
            {
                son[i] = nullptr;
            }
            id = -1;
        }
    }*root;

    void insert(string &word, int id)
    {
        auto p = root;
        for (auto &c : word)
        {
            int u = c - 'a';
            if (!p->son[u]) p->son[u] = new Node();
            p = p->son[u];
        }
        p->id = id;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Node();
        for (int i = 0; i < words.size(); i++) insert(words[i], i);

        int n = board.size(), m = board[0].size();
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        vector<int> ids;
        function<void(int, int, Node*)> dfs = [&](int x, int y, Node *p){
            if (p->id != -1) ids.push_back(p->id);

            char t = board[x][y];
            board[x][y] = '.';

            for (int i = 0; i < 4; i++)
            {
                int a = x + dx[i], b = y + dy[i];
                if (a >= 0 && a < n && b >= 0 && b < m && board[a][b] != '.')
                {
                    int u = board[a][b] - 'a';
                    if (p->son[u])
                        dfs(a, b, p->son[u]);
                }
            }
            board[x][y] = t;
        };

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int u = board[i][j]  - 'a';
                if (root->son[u])
                    dfs(i, j, root->son[u]);
            }
        }

        vector<string> ans;

        for (int &id : ids) ans.emplace_back(words[id]);
        return ans;
    }
};
