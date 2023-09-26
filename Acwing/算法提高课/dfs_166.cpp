#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 9, M = 1 << N;
int nums_one[M], map[M];
char str[100];
int row[N], col[N], grid[3][3];

void init() {
    for (int i = 0; i < N; i ++) row[i] = col[i] = (1 << N) - 1;
    
    for (int i = 0; i < 3; i ++ ){
        for (int j = 0; j < 3; j ++) {
            grid[i][j] = (1 << N) - 1;
        }
    }
}

void draw(int x, int y, int t, bool is_set) {
    if (is_set) str[x * N + y ] = t + '1';
    else str[x * N + y] = '.';
    
    int v = 1 << t;
    if (!is_set) v = -v;
    
    row[x] -= v;
    col[y] -= v;
    grid[x / 3][y / 3] -= v;
}


int lowbit(int x) {
    return x & -x;
}

int get(int x, int y) {
    return row[x] & col[y] & grid[x / 3][y / 3];
}

bool dfs(int cnt) {
    if (!cnt) return true;
    int min_val = 10;
    int x, y;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (str[i * N + j] == '.') {
                int state = get(i, j);
                if (nums_one[state] < min_val) {
                    x = i, y = j;
                    min_val = nums_one[state];
                }
            }
        }
    }
    
    int state = get(x, y);
    
    for (int i = state; i; i -= lowbit(i)) {
        int t = map[lowbit(i)];
        
        draw(x, y, t, true);
        if (dfs(cnt - 1)) return true;
        draw(x, y, t, false);
    }
    return false;
}


int main() {
    for (int i = 0; i < M; i ++) {
        for (int j = 0; j < N; j ++) {
            nums_one[i] += i >> j & 1; 
        }
    } 
    
    for (int i = 0; i < N; i ++) map[1 << i] = i;
    
    while (cin >> str, str[0] != 'e') {
        init();
        
        int cnt = 0;
        
        for (int i = 0, k = 0; i < N; i ++) {
            for (int j = 0; j < N; k ++, j ++) {
                if (str[k] != '.') {
                    int t = str[k] - '1';
                    draw(i, j, t, true);
                }
                else cnt ++;
            }
        }
        dfs(cnt);
        puts(str);
    }
    return 0;
}
