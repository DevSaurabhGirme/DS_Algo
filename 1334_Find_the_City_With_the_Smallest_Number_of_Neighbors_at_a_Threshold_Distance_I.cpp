// T.C = O(V^2)     S.C = O(E*logV)

class Solution {
public:
    #define P pair<int, int>

    void DJK(int n, unordered_map<int, vector<P>>& adjList, vector<int>& result, int Src)
    {
        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, Src});

        fill(result.begin(), result.end(), INT_MAX);

        while (!pq.empty())
        {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // finding neighbors distance
            for(auto& p : adjList[node])
            {
                int adjNode = p.first;
                int dist = p.second;

                if(d + dist < result[adjNode])
                {
                    result[adjNode] = d + dist;
                    pq.push({d+dist, adjNode});
                }
            }
        }
    }

    int findCity(int n, vector<vector<int>>& SPM, int dT)
    {
        int resultCity = -1;

        int leastReachCount = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            int reachCnt = 0;
            for(int j = 0; j < n; j++)
            {
                if(i != j && SPM[i][j] <= dT)
                {
                    reachCnt++;
                }
            }
            if(reachCnt <= leastReachCount)
            {
                leastReachCount = reachCnt;
                resultCity = i;
            }
        }

        return resultCity;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        // matrix to store shortest paths
        vector<vector<int>> SPM(n, vector<int>(n, INT_MAX));   

        for(int i = 0; i < n; i++)
        {
            // filling first cell
            SPM[i][i] = 0;
        }

        // adjacency list for Dijakstra's
        unordered_map<int, vector<P>> adjList;
    
        for(auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
        
            // connecting edges
            // edge and weight
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }

        for(int i = 0; i < n; i++)
        {
            DJK(n, adjList, SPM[i], i);
        }
  
        return findCity(n, SPM, distanceThreshold);

    }
};