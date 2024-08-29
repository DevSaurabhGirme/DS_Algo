// T.C = O(n^2)     S.C = O(n)

class Solution {
public:
    void DFS(vector<vector<int>>& stones, int Idx, vector<bool>& visited)
    {
        // marking current index(stone) as visited(removed)
        visited[Idx] = true;

        for(int i = 0; i < stones.size(); i++)
        {
            // check if either row or column matches
            if(visited[i] == false && (stones[i][0] == stones[Idx][0] || stones[i][1] == stones[Idx][1]))
            {
                DFS(stones, i, visited);
            }
        }

    }

    int removeStones(vector<vector<int>>& stones) 
    {
        int n = stones.size();

        vector<bool> visited(n, false);

        // denotes stones sharing same row or column
        int group = 0;
        for(int i = 0; i < n; i++)
        {
            if(visited[i] != true)
            {
                // to check stones sharing same row or column
                DFS(stones, i, visited);

                group++;
            }
        }

        return n - group;    
    }
};