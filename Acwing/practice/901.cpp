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

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const int  N = 310;
int g[N][N], f[N][N];
int n, m;

int dp(int x, int y) {
	if (f[x][y] != -1)
		return f[x][y];
	f[x][y] = 1;
	for (int i = 0; i < 4; i ++) {
		int a = x + dx[i], b = y + dy[i];
		if (a < 0 || a >= n || b < 0 || b >= m || g[a][b] >= g[x][y])
			continue;
		f[x][y] = max(f[x][y], dp(a, b) + 1);
	} 
	return f[x][y];
}

int main() {
	memset(f, -1, sizeof f);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
			scanf("%d", &g[i][j]);
	int res = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res = max(res, dp(i, j));
	printf("%d\n", res);
	return 0;	
}