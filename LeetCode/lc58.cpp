class Solution {
public:
    int lengthOfLastWord(string s) {
        string res;
        stringstream ssin(s);
        string word;
        while (ssin >> word) res = word;;
        return res.size();


    }
};
