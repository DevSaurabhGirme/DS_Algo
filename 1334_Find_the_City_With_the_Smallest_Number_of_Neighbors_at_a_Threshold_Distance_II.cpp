class Solution {
public:
    void BLF(int n, vector<vector<int>>& edges, vector<int>& result, int Src)
    {
        fill(begin(result), end(result), 1e9 + 7);

        result[Src] = 0;

        for(int i = 1; i < n; i++)
        {
            for(auto &edge : edges)
            {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                if(result[u] != 1e9 + 7 && result[u] + wt < result[v])
                {
                    result[v] = result[u] + wt;
                }

                
                if(result[v] != 1e9 + 7 && result[v] + wt < result[u])
                {
                    result[u] = result[v] + wt;
                }
            }
        }
    }

    int findCity(int n, vector<vector<int>>& SPM, int dT)
    {
        int resultCity = -1;
        int leastReachCount = 1e9 + 7;

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
        vector<vector<int>> SPM(n, vector<int>(n, 1e9 + 7));   

        for(int i = 0; i < n; i++)
        {
            // filling first cell
            SPM[i][i] = 0;
        }
    
        for(auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
        
            SPM[u][v] = wt;
            SPM[v][u] = wt;
        }

        for(int i = 0; i < n; i++)
        {
            BLF(n, edges, SPM[i], i);
        }
  
        return findCity(n, SPM, distanceThreshold);
    }
};
