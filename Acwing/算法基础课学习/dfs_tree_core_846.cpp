// 本题是树的问题 在使用邻接表存储时  可以使用dfs来遍历 （本质上是特殊的图）
// 因为要得到返回节点的信息（子树节点个数）   所以就算是dfs也是后序遍历  后序遍历才能得到信息

// 如果是力扣那种指针存储 需要使用遍历递归函数 traverse 同样也需要使用后序遍历
// labu的方法  构造和遍历  都是递归的思想  需要给出递归函数的定义  并进行递归信任


// 树  图 二维矩阵 都可以用dfs和bfs


// #include <iostream>
// #include <cstring>
// #include <algorithm>

// using namespace std;

// const int N = 100010, M = 2 * N;

// int n;

// bool visited[N]; // 需要定义访问数组
// int h[N], e[M], ne[M], idx; // 有n个队头 所以是h[N] , 因为无向边要存两次  所以2 * N;
// int ans = N;

// void insert(int a, int b){
//     e[idx] = b;
//     ne[idx] = h[a];
//     h[a] = idx ++;
// }

// int bfs(int u){ // 返回以该节点为子树的节点个数
//     visited[u] = true;
    
//     int sum = 1, res = 0; // res 存储的是删除该点后 每一个子树（连通块）的的最大值
    
//     for(int i = h[u]; i != -1; i = ne[i]){
//         int j = e[i];
//         if(!visited[j]){
//             int tmp = bfs(j); // j 不需要再单独设置true了 因为bfs(j) 中已经设置了
//             res = max(res, tmp);
//             sum += tmp;
//         }
//     }
//     res = max(res, n - sum);
//     ans = min(ans, res);
    
//     return sum; // 递归函数需要给出定义 然后进行递归信任  bfs返回的是 以该节点子树的节点个数
// }

// int main(){
//     memset(h, -1, sizeof(h)); // 使用数据结构一定要记得初始化
//     scanf("%d", &n);
//     int a, b;
//     for(int i = 0; i < n - 1; i ++){
//         scanf("%d%d", &a, &b);
//         insert(a, b);
//         insert(b, a);
//     }
    
//     bfs(1);
//     printf("%d\n", ans);
//     return 0;
// }



