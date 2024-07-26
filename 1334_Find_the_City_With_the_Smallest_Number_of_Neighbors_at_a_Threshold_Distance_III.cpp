// T.C = O(n^3)

class Solution {
public:
    void FLW(int n, vector<vector<int>>& SPM)
    {
        for(int via = 0; via < n; via++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    SPM[i][j] = min(SPM[i][j], SPM[i][via] + SPM[via][j]);
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

        FLW(n, SPM);

        return findCity(n, SPM, distanceThreshold);
    }
};
