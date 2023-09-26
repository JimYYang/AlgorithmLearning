#include <iostream>

using namespace std;

const int N = 100010;

int q[N], hh, tt = -1; // 注意hh =0 

void push(int x){
    q[++tt] = x;
}

void pop(){
    hh++;
}

bool empty(){
    return hh > tt;
}

int front(){
    return q[hh];
}

int m;

int main(){
    scanf("%d", &m);
    while(m--){
        string op;
        cin >> op;
        int x;
        if(op == "push"){
            scanf("%d", &x);
            push(x);
        }
        else if(op == "pop"){
            pop();
        }
        else if(op == "query"){
            printf("%d\n", front());
        }
        else{
            if(empty())printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
