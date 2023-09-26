#include<iostream>
#include<vector>

using namespace std;

bool cmp(vector<int>&a, vector<int> & b){
    if(a.size() != b.size())return a.size() > b.size();
    for(int i = a.size() - 1; i >= 0; i--){
        if(a[i] != b[i])return a[i] > b[i];
    }
    return true;
}

vector<int> sub(vector<int> &a, vector<int> &b){
    int carry = 0;
    vector<int> c;
    for(int i = 0; i < a.size(); ++i){
        carry = a[i] - carry;//记住做的是A-B，所以a要减去借位和b
        if(i < b.size())carry -= b[i];
        c.push_back((carry + 10) % 10);
        if(carry < 0)carry = 1;
        else carry = 0;
    }
    while(c.size() > 1 && c.back() == 0)c.pop_back();
    return c;
}
int main(){
    string a, b;
    vector<int>A, B;
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0 ; i--)A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0 ; i--)B.push_back(b[i] - '0');
    
    vector<int>c;
    if(cmp(A, B)){c = sub(A, B);
    for(int i = c.size() - 1; i >= 0; i--)printf("%d", c[i]);
    }
    else {c = sub(B, A);
    printf("-");
    for(int i = c.size() - 1; i >= 0; i--)printf("%d", c[i]);
    }
    return 0;
}
