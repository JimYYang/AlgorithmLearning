#include <iostream>

using namespace std;

const int N = 100010;

int son[N][26], cnt[N], idx; // 注意都被初始化为0
char str[N];
void insert(char str[]){
    int p = 0;
    for(int i = 0; str[i]; ++i){
        int u = str[i] - 'a';
        if(!son[p][u])son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char str[]){
    int p = 0;
    for(int i = 0; str[i]; ++i){
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main(){
    int n;
    scanf("%d", &n);
    char s[5];
    while(n--){
        char op; // 或者定义op[2]的数组也可以
        scanf(" %c%s", &op, str);
        if(op == 'I')insert(str);
        else printf("%d\n", query(str));
    }
    return 0;
}
