#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 5010;
PII h[N];
int p[N];
int n;

int main(){
    cin >> n;
    // int a, b;
    for(int i = 0; i < n; i ++){
        // cin >> a >> b;
        // h[i] = {a, b};
        cin >> h[i].x >> h[i].y;
    }
    
    sort(h, h + n);  // 注意 排序的时候如果从1开始存  那排序也应该从1开始 要么都从0开始
    
    int piles = 0;
    for(int i = 0; i < n; i ++){
        int tar = h[i].y;
        int l = 0, r = piles - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            
            if(p[mid] >= tar)
                r = mid - 1;
            else l = mid + 1;
        }
        
        if(piles == l){
            piles ++;
        }
        p[l] = tar;
    }
    
    cout << piles << '\n';
    
    return 0;
}
