关与bfs 有两种写法  labu的写法要注意depth的初值设置为几  以及在判断条件  在哪里退出循环  一般来说增加的dist会比实际多1 如果在判断那里就处理或者退出 是正确的



int minDepth(TreeNode root) {
    if (root == null) return 0;
    Queue<TreeNode> q = new LinkedList<>();
    q.offer(root);
    // root 本身就是一层，depth 初始化为 1
    int depth = 1;

    while (!q.isEmpty()) {
        int sz = q.size();
        /* 将当前队列中的所有节点向四周扩散 */
        for (int i = 0; i < sz; i++) {
            TreeNode cur = q.poll();
            /* 判断是否到达终点 */
            if (cur.left == null && cur.right == null) 
                return depth;
            /* 将 cur 的相邻节点加入队列 */
            if (cur.left != null)
                q.offer(cur.left);
            if (cur.right != null) 
                q.offer(cur.right);
        }
        /* 这里增加步数 */
        depth++;
    }
    return depth;
}

y的写法  不会出错

y的方法:
有向图 初始化dist为-1 和0x3f都可以 但是记得判断路径不存在的情况
无向图 初始化为0x3f 否则距离会被不断更新  （也不一定）

const int N = 100010;

int h[N], e[N * 2], ne[N * 2], idx;
int dist[N];

class Solution {
public:
    void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
    }

    void dfs(TreeNode* root) {
        // 不需要判空 因为空的没有边
        if (root->left) {
            add(root->val, root->left->val);
            add(root->left->val, root->val);
            dfs(root->left);
        }
        if (root->right) {
            add(root->val, root->right->val);
            add(root->right->val, root->val);
            dfs(root->right);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        memset(h, -1, sizeof h);
        idx = 0;

        dfs(root);
        queue<int> q;
        q.push(start);
        memset(dist, 0x3f, sizeof dist);
        dist[start] = 0;

        int res = 0;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            res = max(res, dist[t]);

            for (int i = h[t]; ~i; i = ne[i]) {
                int j = e[i];
                if (dist[j] > dist[t] + 1) {
                    dist[j] = dist[t] + 1;
                    q.push(j);
                }
            }
        }

        return res;
    }
};
