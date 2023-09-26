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
    int smallestDivisor(vector<int>& nums, int threshold) {
    	int left = 1, right = *max_element(nums.begin(), nums.end());

    	function<bool(int)> check = [&](int div) {
    		int sum = 0;
    		for (auto num : nums)
    			sum += (num + div - 1) / div;
    		return sum <= threshold;
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
	vector<int> a {1, 2, 5, 9};
	cout << sol.smallestDivisor(a, 6);
	return 0;
}
