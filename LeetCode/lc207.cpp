class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> inDegrees(numCourses);
        for (auto &prerequisite : prerequisites)
        {
            auto b = prerequisite[0], a = prerequisite[1];
            edges[a].push_back(b);
            inDegrees[b]++;
        }

        auto topSort = [&]() {
            queue<int> que;

            for (int i = 0; i < numCourses; i++)
            {
                if (!inDegrees[i])
                    que.push(i);
            }

            while (!que.empty())
            {
                auto cur = que.front();
                que.pop();

                numCourses--;
                for (auto node : edges[cur])
                {
                    inDegrees[node]--;
                    if (!inDegrees[node])
                        que.push(node);
                }
            }
            return numCourses == 0;
        };

        return topSort();
    }
};