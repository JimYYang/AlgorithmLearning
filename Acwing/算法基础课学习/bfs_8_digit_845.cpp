#include <iostream>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <algorithm>

using namespace std;

// bfs有几点需要完成的工作
// 1. 访问过的状态used
// 2. 定义一个队列
// 3. dist数组  可以使用数组 哈希表
// 4. 状态转移

int bfs(string & start){
    string end = "12345678x";
    queue<string>q;
    unordered_map<string, int>d;
    
    q.push(start);
    d[start] = 0;
    
    int direc[4][4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; 
    
    while(q.size()){
        auto cur = q.front();
        q.pop();
        
        int dist = d[cur];
        
        if(cur == end)return dist;
        
        int pos = cur.find('x');
        int x = pos / 3, y = pos % 3, a, b;
        for(int i = 0; i < 4; i ++){
            a = x + direc[i][0], b = y + direc[i][1]; // 一维坐标变为二维坐标
            if(a >= 0 && a < 3 && b >= 0 && b < 3){
            swap(cur[pos], cur[a * 3 + b]); // 假想将字符串变为了矩阵 但是实际上没有 只是进行坐标变化 
            // 再将二维坐标变为一维坐标
            if(!d.count(cur)){
                d[cur] = dist + 1;
                
                q.push(cur);
            }
            swap(cur[pos], cur[a * 3 + b]); // 注意这里恢复过来的原因是为下一次交换做准备
            }
        }
    }
   return -1; // bfs如果循环中没有找到那就说明没有答案
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    string start;
    //start.insert(0, 1, 'a'); 开头插入一个字符
    cout << start;
    
    char c;
    for(int i = 0; i < 9; i ++){
        cin >> c;
        // start += c; //str = str + 'a' 右值产生一个新的副本，再把副本赋给 str
        //str += 'a' 把后面的数值自动强制转换为前面的类型，然后在那块内存上直接修改数值，避免了产生新的副本，效率更高
        start.append(1, c);
    }
    
    cout << bfs(start) << '\n';
    return 0;
}
