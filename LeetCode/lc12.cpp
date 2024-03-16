class Solution {
public:
    string intToRoman(int num) {
        int values[] = {
            1000,
            900, 500, 400, 100,
            90, 50, 40, 10,
            9, 5, 4, 1
        };

        string reps[] = {
            "M",
            "DM", "D", "CD", "C",
            "XC", "L", "XL", "X",
            "IX", "V", "IV", "I"
        };

        string res;
        for (int i = 0; i < 13; i++)
        {
            if (num >= values[i])
            {
                num -= values[i];
                res += reps[i];
            }
        }
        return res;
    }
};
