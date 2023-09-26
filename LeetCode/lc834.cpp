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

typedef long long ll;
typedef pair<int, int> PII;


const int  N = 1e5 + 10;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    	vector<vector<int>> g(n);

    	for (auto& edge : edges) {
    		int a = edge[0], b = edge[1];
    		g[a].push_back(b);
    		g[b].push_back(a);
    	}
    	vector<int> ans(n);
    	vector<int> size(n, 1);
    	function<void(int, int, int)> dfs = [&](int u, int fa, int depth) -> void {
    		ans[0] += depth;
    		for (auto son : g[u]) {
    			if (son == fa)
    				continue;
    			dfs(son, u, depth + 1);
    			size[u] += size[son];
    		}
    	};
    	dfs(0, -1, 0);

    	function<void(int, int)> reroot = [&](int u, int fa) -> void {
    		for (auto son : g[u]) {
    			if (son == fa)
    				continue;	
    			ans[son] = ans[u] + n - 2 * size[son];
    			reroot(son, u);
    		}
    	};
    	reroot(0, -1);
    	return ans;
    }
};
