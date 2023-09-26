#include <iostream>

using namespace std;

const int N = 10;

int path[N];
bool used[N];
int n;

void dfs(int u){
    if(u == n){
        for(int i = 0; i < n; ++i)printf("%d ", path[i]);
        puts("");
        return ;
    }
    else{
        for(int i = 1; i <= n; ++i){
            if(!used[i]){
                path[u] = i;
                used[i] = true;
                dfs(u + 1);
                used[i] = false;
            }
        }
    }
}
int main(){
    scanf("%d", &n);;
    dfs(0);
    return 0;
}
