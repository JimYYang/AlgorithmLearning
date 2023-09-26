#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;
int m;
int idx, e[N], l[N], r[N];

// 双链表中0 1下标分别表示头结点和尾节点  是不用的  插入操作的idx从2开始

// 一个常见的错误是忘了调用inti()函数
void init(){
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}
 
void insert(int k, int x){// 在第k后面插入
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
    idx ++;
}
void remove(int k){
    // r[l[k]] = r[k];
    l[r[k]] = l[k];
    r[l[k]] = r[k];
}
int main(){
    init();
    scanf("%d", &m);
    while(m--){
        string op;
        int k, x;
        cin >> op;// 用scanf方法读入字符串较为麻烦 需要事先开辟空间
        if(op == "L"){
            scanf("%d", &x);
            insert(0, x);
        }else if(op == "R"){
            scanf("%d", &x);
            insert(l[1], x);
        }else if(op == "D"){
            scanf("%d", &k);
            remove(k + 1);// 注意题目的k从几开始 完成下标的对应
        }else if(op == "IL"){
            scanf("%d%d", &k, &x);
            insert(l[k+1], x);
        }else{
            scanf("%d%d", &k, &x);
            insert(k + 1, x);
        }
    }
    for(int i = r[0]; i != 1; i = r[i])printf("%d ", e[i]);
    return 0;
}
