#include<iostream>

using namespace std;

// yxc没有具体提到滑动窗口  但是本质就是双指针  参考自己学过的总结一下即可


const int  N = 100010;
int n;
int q[N], s[N];

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i)scanf("%d", &q[i]);
    int j = 0, res = 0;
    for(int i = 0; i < n; ++i){
        s[q[i]]++;
        while(j <= i && s[q[i]] > 1){
            s[q[j]]--;
            j++;
        }
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}
