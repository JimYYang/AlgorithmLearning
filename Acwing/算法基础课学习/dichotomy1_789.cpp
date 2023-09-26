#include<iostream>

using namespace std;

//该方法是力扣二分法前提是非降序排列（降序也可以）
//注意第一个>=指的是左边界  就算没有返回数组长度  也可能不存在目标值（第一个比目标值大的值）
const int N = 100010;
int n, k;
int q[N];
bool flag = 0;
int find_left(int n, int tar){
    int left = 0, right = n - 1;
        while(left <= right){
            int mid = (left + right) >> 1;
            if(q[mid] == tar)flag = 1;
            if(q[mid] >= tar)right = mid - 1;
            else left = mid + 1;
        }
        return left;
}

int find_right(int n, int tar){
    int left = 0, right = n - 1;
        while(left <= right){
            int mid = (left + right) >> 1;
            if(q[mid] == tar)flag = 1;
            if(q[mid] >tar)right = mid - 1;
            else left = mid + 1;
        }
        return right;
}

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i)scanf("%d", &q[i]);
    while(k--){
        int tar;
        scanf("%d", &tar);
        int l = find_left(n, tar), r = find_right(n, tar);
        if( l == n || r == -1){
            cout <<"-1 -1"<<endl;
            continue;
        }
        if(q[l] != tar || q[r] != tar){
            cout <<"-1 -1"<<endl;
            continue;
        }
        
        cout << l <<" " << r <<endl;
    }
    return 0;
}
