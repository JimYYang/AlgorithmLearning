#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 30;

int q[100], path[N];
int op[8][7] = {
    {0, 2, 6, 11, 15, 20, 22},
    {1, 3, 8, 12, 17, 21, 23},
    {10, 9, 8, 7, 6, 5, 4},
    {19, 18, 17, 16, 15, 14, 13},
    {23, 21, 17, 12, 8, 3, 1},
    {22, 20, 15, 11, 6, 2, 0},
    {13, 14, 15, 16, 17, 18, 19},
    {4, 5, 6, 7, 8, 9, 10}
};

int inverse[] = {5, 4, 7, 6, 1, 0, 3, 2};
int center[] = {6, 7, 8, 11, 12, 15, 16, 17};
int f() {
    int sum[4] = {0};
    
    for (int i = 0; i < 8; i ++) sum[q[center[i]]] ++;
    
    int s = 0;
    for (int i = 1; i <= 3; i ++) s = max(s, sum[i]);
    return 8 - s;
}


void operation(int x) {
    int temp = q[op[x][0]];
    for (int i = 0; i < 6; i ++) q[op[x][i]] = q[op[x][i + 1]];
    q[op[x][6]] = temp;
}

bool check() {
    for (int i = 1; i < 8; i ++) {
        if (q[center[i]] != q[center[0]])
            return false;
    }
    return true;
}

bool dfs(int depth, int max_depth, int last) {
    if (depth + f() > max_depth) return false;
    if (check()) return true;
    for (int i = 0; i < 8; i ++) {
        if (inverse[i] == last) continue;
        operation(i);
        path[depth] = i;
        if (dfs(depth + 1, max_depth, i)) return true;
        operation(inverse[i]);
    }
    
    return false;
}



int main() {
    while (scanf("%d", &q[0]), q[0]) {
        for (int i = 1; i < 24; i ++) scanf("%d", &q[i]);
        
        int depth = 0;
        while (!dfs(0, depth, -1)) depth ++;
        
        if (!depth) printf("No moves needed");
        for (int i = 0; i < depth; i ++) printf("%c", 'A' + path[i]);
        printf("\n%d\n", q[6]);
    }
    return 0;
}
