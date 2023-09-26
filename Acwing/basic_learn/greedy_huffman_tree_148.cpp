// 区间dp是合并相邻的两堆  这个是任意合并两个
// 这样合并（构造）得到的最优是哈夫曼树并且由于特殊 是完全二叉树 哈夫曼树是最优二叉树（带权路径最短） 不一定是完全二叉树
// 贪心的一种证明思路是交换后结果会更好  或者不会变差

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    
    priority_queue<int, vector<int>, greater<int>> hp;
    
    int x;
    
    while(n--){
        scanf("%d", &x);
        hp.push(x);
    }
    
    int res = 0;
    int min1, min2;
    while(hp.size() > 1){
        min1 = hp.top();
        hp.pop();
        min2 = hp.top();
        hp.pop();
        res += min1 + min2;
        hp.push(min1 + min2);
    }
    
    printf("%d\n", res);
    
    return 0;
}
