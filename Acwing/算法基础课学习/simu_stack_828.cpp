#include <iostream>

using namespace std;

const int N = 100010;

int stk[N], tt;//注意tt等于0

void push(int x){
    stk[ ++ tt] = x;
}

void pop(){
    tt--;
}

bool empty(){
    return tt == 0;
}

int top(){
    return stk[tt];
}

int m;

int main(){
    scanf("%d", &m);
    while(m--){
        string op;
        int x;
        cin >> op;
        if(op == "push"){
            scanf("%d", &x);
            push(x);
        }else if(op == "pop"){
            pop();
        }else if(op == "query"){
            printf("%d\n", top());
        }else{
            if(empty())printf("YES\n");
            else printf("NO\n");// bool 类型在scanf 用整数输出
        }
    }
    return 0;
}
