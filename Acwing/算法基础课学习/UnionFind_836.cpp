#include <iostream>

using namespace std;

const int N = 100010;

int p[N];

int n, m;

int find(int x){
    if(p[x] != x)p[x] = find(p[x]);
    return p[x];
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)p[i] = i; // 从几开始无所谓
    
    while(m--){
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if(op[0] == 'M')p[find(a)] = find(b); // 不用判断  如果在一个集合中这个也是对的  
                                              // 因为find(a) = find(b) 在一个集合说明 有同一个祖宗 祖宗满足p[x] = x
        else{
            if(find(a) == find(b))puts("Yes");
            else puts("No");
        }
    }
    return 0;
}



/*******************************************************************
 *  关于并查集 本题中的模板较为初级  还有更为一般的实现方法
 *  首先并查集描述的是等价关系  可以将元素分门别类
 *  这里所说的「连通」是一种等价关系，也就是说具有如下三个性质：
 *
 *   1、自反性：节点p和p是连通的。
 *
 *   2、对称性：如果节点p和q连通，那么q和p也连通。
 *
 *   3、传递性：如果节点p和q连通，q和r连通，那么p和r也连通。
 *
 *  解决的问题  ：
 * 1、 判断是否连通（在一个集合中）
 * 2、 找连通分量的数量（一共有几类）
 * 3、 合并集合
 * 4、 寻找公共祖先  
 * 
 * 再使用并查集的时候往往可以增加dummy节点  辅助分类
 * LC 323  990题
 * 
 *  优化方式有两个
 * 1、 find归并  2、按秩合并（把小的接在大的上面）（第二种在大多数情况下没有必要）
 * 
 * 常见模板
 * 
 * 用数组存储   数组值为负数时代表为祖宗节点， 且负数的绝对值代表这一类的数量  
 *                    为正数时表示的是自己的祖宗节点
 * class UF{
	private:
		int cnt;
		vector<int>parent;
	
	public:
		UF(int n = 0){
			cnt = n;
			parent = vector<int>(n, -1);
		}
		void Union(int p, int q){
			int root_p = find (p);
			int root_q = find (q);
			if(root_p == root_q)return;
			if(parent[root_p] > parent[root_q]){
				parent[root_q] += parent[root_p];
				parent[root_p] = root_q;
			}else{
				parent[root_p] += parent[root_q];
				parent[root_q] = root_p;
			}
			cnt--;
		}

		bool connected(int p, int q){
			return find(p) == find(q);
		}

		int count(){
			return cnt;
		}

        int find(int target){
			//二种方法
			if(parent[target] < 0)return target;
			return parent[target] = find(parent[target]);
			
			
			// while(parent[target] >= 0){
			// 	parent[target] = parent[parent[target]];
			// 	target = parent[target];
			// }
			// return target;
		}

};
 * 
 * 
 * 
 * 
 * 
 * 
 * 
*/ 
