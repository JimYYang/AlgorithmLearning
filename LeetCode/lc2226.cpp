#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <utility>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;


const int  N = 1e5 + 10;

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int l = 0, r = *max_element(candies.begin(), candies.end());
        function <bool(int)> check = [&](int n) -> bool {
            LL s = 0;
            for (int candy : candies)
                s += candy / n;
            return s >= k;
        };
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(mid))
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};

int main() {
	Solution sol;
	vector<int> a {4, 7, 5};
	cout << sol.maximumCandies(a, 4);
	return 0;
}
