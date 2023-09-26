#include <iostream>
#include <cstdio>
#include <cmath>
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
#include <iomanip>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;


const int  N = 1e5 + 10;

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        LL h100 = llround(hour * 100);
        if (h100 <= (n - 1ll) * 100)
            return -1;
        int left = 1, right = 1e7;
        function <bool(int)> check = [&](int v) -> bool {
            LL sum = 0;
            for (int i = 0; i < n - 1; i++)
                sum += (dist[i] + v - 1ll) / v;
            sum = (sum * v + dist[n - 1]) * 100;
            return sum <= h100 * v;
        };

        while (left < right) {
            int mid = left + right >> 1;
            if (check(mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

int main() {
	Solution sol;
	vector<int> a {69};
	cout << sol.minSpeedOnTime(a, 4.6);
    double number = 2.0111;
    LL result = static_cast<int>(number * 100);
    cout << '\n' << "****" << result;
	return 0;
}
