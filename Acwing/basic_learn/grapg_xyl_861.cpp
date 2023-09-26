#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;


const int N = 510, M = 100010; // 只需要键单向边

int n1, n2, m;

int idx, e[M], h[M], ne[M];
int match[N];
bool used[N];

void insert(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}


bool find(int x){
    for(int i = h[x]; i != -1; i = ne[i]){
        int j = e[i];
        if(!used[j]){ //还没被考虑过
            used[j] = true;
            
            if(match[j] == 0 || find(match[j])){
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    scanf("%d%d%d", &n1, &n2, &m);
    
    memset(h, -1, sizeof h);
    
    // int a, b;
    
    while(m --) {
        int a, b;
        scanf("%d%d", &a, &b);
        insert(a, b);
    }
    
    int res = 0;
    
    for(int i = 1; i <= n1; i ++){
        memset(used, false, sizeof used); // used数组在每一轮循环中 起到防止死循环的作用
        //st数组用来保证本次匹配过程中，第二个集合中的每个点只被遍历一次，防止死循环。
        //match存的是第二个集合中的每个点当前匹配的点是哪个，但就算某个点当前已经匹配了某个点，也有可能被再次遍历，
        //所以不能起到判重的作用。


        //st数组可以理解为预定数组，即某一轮中某个女孩是不是被男生预定了。
        //如果find函数递归下去能够帮心仪对象的对象找到备胎，那皆大欢喜，所有这一轮预定的姑娘被match对应的男孩（回溯）。
        //如果找不到备胎，那这些预定姑娘就保持不动。

        //没有st数组会导致爆栈。举个简单例子：左1、左2都指向右1，执行find(1)后会使得match[1] = 1，
        //接着执行find(2)时，需执行find(1)，find(1)又需执行find(1)，如此进入了死循环，导致爆栈。


        
        if(find(i)) res ++;
    }
    printf("%d\n", res);
    return 0;
}
