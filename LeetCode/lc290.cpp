class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ssin(s);
        string word;
        while (ssin >> word) words.push_back(word);
        if (pattern.size() != words.size())
            return false;

        unordered_map<char, string> pw;
        unordered_map<string, char> wp;

        for (int i = 0; i < pattern.size(); i++)
        {
            char a = pattern[i];
            string b = words[i];
            if (pw.count(a) && pw[a] != b)
                return false;
            pw[a] = b;

            if (wp.count(b) && wp[b] != a)
                return false;
            wp[b] = a;
        }
        return true;
    }
};
