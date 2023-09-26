#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;


int n;
vector<int> get_divisors(int n){
    vector<int> res;
    
    for(int i = 1; i <= n / i; i ++){
        if(n % i == 0){
            res.push_back(i);
            if( i != n / i)
                res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    
    return res;
}

int main(){
    scanf("%d", &n);
    
    int x;
    while(n --){
        scanf("%d", &x);
        
        auto res = get_divisors(x);
        for(auto & c : res)printf("%d ", c);
        puts("");
    }
    return 0;
}


