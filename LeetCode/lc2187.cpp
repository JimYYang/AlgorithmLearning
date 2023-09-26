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
    long long minimumTime(vector<int>& time, int totalTrips) {
    	int n = time.size();
        LL l = 1, r = (n + totalTrips - 1ll) / n * (*max_element(time.begin(), time.end()));

        function <bool(LL)> check = [&](LL t) -> bool {
        	LL s = 0;
        	for (auto c : time)
        		s += t / c;
        	return s >= totalTrips;	
        };
        while (l < r) {
        	LL mid = l + r >> 1;
        	if (check(mid))
        		r = mid;
        	else
        		l = mid + 1;
        }
        return l;
    }
};

int main() {
	Solution sol;
	vector<int> a {5, 10, 10};
	cout << sol.minimumTime(a, 9);
	return 0;
}
