// T.C = O(m+n)     S.C = O(n)

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) 
    {
        // maintain count of indegrees of each node
        vector<int> indegree(n, 0);
    
        for(vector<int>& edge : edges) 
        {
            int u = edge[0];
            int v = edge[1];

            indegree[v]++;
        }

        // champion
        int champ = -1;

        // count of champions
        int count = 0;
        
        for(int i = 0; i < n; i++) 
        {
            if(indegree[i] == 0) 
            { 
                //ith node is the champion
                champ = i;
                
                count++;
                
                // more than one champion
                if(count > 1) 
                {
                    return -1;
                }
            }
        }

        return champ;
    }
};