class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26] = {0};
        int n = ransomNote.size();
        for (char &c : ransomNote) cnt[c - 'a']++;

        for (char &c : magazine)
        {
            if (cnt[c - 'a'])
            {
                cnt[c - 'a']--;
                n--;
            }
            if (!n) return true;
        }
        return false;
    }
};
