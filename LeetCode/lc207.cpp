class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        queue<int> que;
        vector<int> inDegree(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int b = prerequisites[i][0], a = prerequisites[i][1];
            edges[a].push_back(b);
            inDegree[b]++;
        }

        auto topSort = [&]() -> bool{
            int cnt = 0;
            for (int i = 0; i < numCourses; i++)
            {
                if (!inDegree[i])
                {
                    que.push(i);
                }
            }

            while (que.size())
            {
                int cur = que.front();
                que.pop();
                cnt++;
                for (int &edge : edges[cur])
                {
                    if (--inDegree[edge] == 0)
                    {
                        que.push(edge);
                    }
                }
            }
            return cnt == numCourses;
        };
        return topSort();
    }
};
