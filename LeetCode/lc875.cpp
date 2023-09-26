#include <iostream>
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
    int minEatingSpeed(vector<int>& piles, int h) {
    	int left = 1, right = *max_element(piles.begin(), piles.end());

    	function<bool(int)> check = [&](int v) -> bool{
    		LL cnt = 0;
    		for (auto pile : piles)
				// cnt += pile / v + 1;
    			cnt += (pile + v - 1) / v;
    		return cnt <= h;
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
	vector<int> a {1000000000};
	cout << sol.minEatingSpeed(a, 2);
	return 0;
}
