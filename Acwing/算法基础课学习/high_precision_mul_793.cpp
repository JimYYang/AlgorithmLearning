#include<iostream>
#include<vector>

using namespace std;

vector<int> mul(vector<int>& a, int b){
    vector<int> c;
    int carry = 0;
    
    for(int i = 0; i < a.size() || carry ; ++i){
        if(i < a.size())carry += a[i] * b;
        c.push_back(carry % 10);
        carry /= 10;
    }
    while(c.size() > 1 && c.back() == 0)c.pop_back();
    return c;
}


int main(){
    string a;
    int b;
    cin >> a >> b;
    vector<int>A;
    for(int i = a.size() - 1; i >= 0; i --)A.push_back(a[i] - '0');
    vector<int>c = mul(A, b);
    for(int i = c.size() - 1; i >= 0; i--)printf("%d", c[i]);
}
