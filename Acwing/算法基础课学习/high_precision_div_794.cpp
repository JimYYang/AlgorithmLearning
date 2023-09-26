#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> div(vector<int>& a, int b ,int & r){
    vector<int>c;
    for(int i = a.size() - 1; i >= 0; i--){
        r = 10 * r + a[i];
        c.push_back(r / b);
        r %= b;
    }
    
    reverse(c.begin(), c.end());
    while(c.size() > 1 && !c.back())c.pop_back();
    return c;
}

int main(){
    string a;
    int b;
    
    cin >> a >> b;
    vector<int>A;
    for(int i = a.size() - 1; i >= 0; i --)A.push_back(a[i] - '0');
    
    vector<int>c;
    int r = 0;
    c = div(A, b, r);
    for(int i = c.size() - 1; i >= 0; i --)printf("%d", c[i]);
    printf("\n%d\n", r);
    return 0;
    
}
