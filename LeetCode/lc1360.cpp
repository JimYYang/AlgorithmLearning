class Solution {
public:
    int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool is_leap(int n)
    {
        return n % 100 && n % 4 == 0 || n % 400 == 0;
    }

    int get(string s)
    {
        int res = 0;
        int y, m, d;
        sscanf(s.c_str(), "%d-%d-%d", &y, &m, &d);

        for (int i = 1970; i < y; i++) res += 365 + is_leap(i);

        for (int i = 1; i < m; i++)
        {
            if (i == 2) res += 28 + is_leap(y);
            else res += months[i];
        }
        return res + d;
    }

    int daysBetweenDates(string date1, string date2) {
        return abs(get(date1) - get(date2));
    }
};
