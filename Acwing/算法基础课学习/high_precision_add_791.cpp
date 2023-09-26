#include<iostream>
#include<vector>

using namespace std;

vector<int> add(vector<int> & a, vector<int> & b){
    int carry = 0; 
    vector<int> c;
    for(int i = 0; i < a.size() || i < b.size(); i ++){
        if(i < a.size())carry += a[i];
        if(i < b.size())carry += b[i];
        c.push_back(carry % 10);
        carry /= 10;
    }
    if(carry)c.push_back(carry);
    return c;
}
int main() {
    string a, b;
    vector<int>A, B;
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; i --)A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i --)B.push_back(b[i] - '0');
    auto c = add(A, B);
    for(int i = c.size() - 1; i >= 0; i --)printf("%d", c[i]);
    return 0;
}
