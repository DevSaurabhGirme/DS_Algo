// T.C = O(V*logE)  S.C = O(V+E)

class Solution {
public:
    #define P pair<int, int>

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) 
    {
        unordered_map<int, vector<int>> graph;

        for(auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            // connecting edges
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> min_d1(n+1, INT_MAX);
        vector<int> min_d2(n+1, INT_MAX);    

        // min_heap to store distance and node
        priority_queue<P, vector<P>, greater<P>> min_pq;

        // time = 0, destination = 1(for source = 1)
        min_pq.push({0, 1});
        // time between source = 1 and destination = 1
        min_d1[1] = 0;

        while(!min_pq.empty())
        {
            auto[timePassed, node] = min_pq.top();
            min_pq.pop();
        
            if(node == n && min_d2[n]!= INT_MAX)
            {
                return min_d2[n];
            }

            int interval = timePassed/change;
            if(interval % 2 == 1)
            {
                // odd = red
                // even = green
                timePassed = (interval + 1) * change;
            }

            for(auto &nhbr : graph[node])
            {
                if(min_d1[nhbr] > timePassed + time)
                {
                    min_d2[nhbr] = min_d1[nhbr];
                    min_d1[nhbr] = timePassed + time;
                    min_pq.push({timePassed + time, nhbr});
                }
                else if(min_d2[nhbr] > timePassed + time && min_d1[nhbr] != timePassed + time)
                {
                    min_d2[nhbr] = timePassed + time;
                    min_pq.push({timePassed  + time, nhbr});
                }
            }
        }
        return -1;
    }
};