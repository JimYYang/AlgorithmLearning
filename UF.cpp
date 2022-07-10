#include<bits/stdc++.h>
using namespace std;

class UF{
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