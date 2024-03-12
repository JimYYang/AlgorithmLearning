class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string res;
        int carry = 0;
        for (int i = 0; i < a.size() || i < b.size() || carry; i++)
        {
            if (i < a.size()) carry += a[i] - '0';
            if (i < b.size()) carry += b[i] -'0';
            res.push_back(carry % 2 + '0');
            carry /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
