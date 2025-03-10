class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int sLen = s.size(), wordLen = words[0].size(), numOfWords = words.size();

        unordered_map<string, int> totWords;
        for (const auto & word : words) totWords[word]++;

        vector<int> res;
        for (int i = 0; i < wordLen; i++)
        {
            // 因为循环里面要用j开始，长度为wordLen的子串
            int cnt = 0;
            unordered_map<string, int> window;
            for (int j = i; j + wordLen <= sLen; j+= wordLen)
            {
                // j只是当前要加进去的最后一个的起点
                if (j - i >= numOfWords * wordLen)
                {
                    auto word = s.substr(j - numOfWords * wordLen, wordLen);
                    window[word]--;
                    if (window[word] < totWords[word])
                    {
                        cnt--;
                    }
                }
                auto word = s.substr(j, wordLen);
                window[word]++;
                if (window[word] <= totWords[word]) cnt++;
                if (cnt == numOfWords) res.push_back({j - (numOfWords - 1) * wordLen});
            }
        }
        return res;
    }
};
