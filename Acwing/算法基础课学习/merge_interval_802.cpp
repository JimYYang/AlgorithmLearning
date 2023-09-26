#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;
int n;
vector<PII>a;

void merge(vector<PII>& a){
    vector<PII> res;
    res.push_back(a[0]);
    for(auto cur = a.begin() + 1; cur != a.end(); ++cur){
        if((*cur).first <= res.back().second){
           res.back().second = max((*cur).second, res.back().second); 
        }else{
            res.push_back(*cur);
        }
    }
    a = res;
}

void merge2(vector<PII>& a){
    vector<PII>res;
    int st = -2e9, ed = -2e9;
    //手动维护两个区间端点
    for(int i = 0; i < a.size(); ++i){
        if(ed < a[i].first){
            if(st != -2e9) res.push_back({st, ed});
            st = a[i].first, ed = a[i].second;
        }else ed = max(ed, a[i].second);
    }
    
    if(st != -2e9)res.push_back({st, ed});
    a = res;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int l, r;
        scanf("%d%d", &l, &r);
        a.push_back({l,r});
    }
    sort(a.begin(), a.end());// 会默认先排序第一个  在排序第二个  升序
    merge2(a);
    cout << a.size();
    return 0;
}
