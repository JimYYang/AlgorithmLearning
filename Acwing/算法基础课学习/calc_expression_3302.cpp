// #include <iostream>
// #include <cstring>
// #include <stack>
// #include <algorithm>
// #include <unordered_map>
// #include <cmath>
#include <bits/stdc++.h>

using namespace std;

stack<int> num;
stack<char> op;

void calc(){
    auto b = num.top(); num.pop();
    auto a = num.top(); num.pop();
    auto c = op.top(); op.pop();
    int x;
    if(c == '+') x = a + b;
    else if(c == '-') x = a - b;
    else if(c == '*') x = a * b;
    else if(c == '/') x = a / b;
    else x = pow(a, b);
    num.push(x);
}

int main(){
    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};
    string str;
    getline(cin, str);
    // cin >> str;
    for(int i = 0; i < str.size(); i++){
        auto c = str[i];
        if(c == ' ')continue;
        if(isdigit(c)){
            int x = 0, j = i;
            while(j < str.size() && isdigit(str[j]))
                x = x * 10 + str[j++] - '0';
            i = j - 1;// 因为退出while循环时j已经加1了 而for循环体中i还会再次加1
            num.push(x);
        }
        else if( c == '(' || c == '^')op.push(c);
        else if( c == ')'){
            while(op.top() != '(')calc();
            op.pop();// (出栈
        }
        else{
            while(op.size() && pr[op.top()] >= pr[c])calc();
            op.push(c);
        }
    }
    while(op.size())calc();// 此时还剩一个运算符  需要再计算一次
    printf("%d\n", num.top());
}
