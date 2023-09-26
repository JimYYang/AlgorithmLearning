#include<iostream>

using namespace std;

const int N = 100010;
int n, k;
int q[N];


int main(){
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i)scanf("%d", &q[i]);
    
    while(k--){
        int tar;
        scanf("%d", &tar);
        
        int l = 0, r = n - 1;
        while(l < r){
            int mid = (l + r) >> 1;
            if(q[mid] >= tar)r = mid;
            else l = mid + 1;
        }
        if(q[l] != tar)cout << "-1 -1" << endl;
        else{
            cout << l << ' ';
            l = 0, r = n - 1;
            while(l < r){
                int mid = (l + r + 1) >> 1;
                if(q[mid] <= tar)l = mid;
                else r = mid - 1;
            }
            cout << r <<endl;
        }
    }
    return 0;
}

