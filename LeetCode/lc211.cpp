class WordDictionary {
public:
    struct Node
    {
        Node *son[26];
        bool isEnd;
        Node ()
        {
            for (int i = 0; i < 26; i++)
            {
                son[i] = nullptr;
            }
            isEnd = false;
        }
    };
    Node *root;

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        auto p = root;
        for (auto c : word)
        {
            int u = c  - 'a';
            if (!p->son[u]) p->son[u] = new Node();
            p = p->son[u];
        }
        p->isEnd = true;
    }
    
    bool search(string word) {
        function<bool(Node*, int)> dfs = [&](Node *p, int i)
        {
            if (i == word.size()) return p->isEnd;
            if (word[i] != '.')
            {
                int u = word[i] - 'a';
                if (!p->son[u]) return false;
                return dfs(p->son[u], i + 1);
            }
            else
            {
                for (int j = 0; j < 26; j++)
                {
                    if (p->son[j] && dfs(p->son[j], i + 1))
                        return true;
                }
                return false;
            }
            return false;
        };
        return dfs(root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */