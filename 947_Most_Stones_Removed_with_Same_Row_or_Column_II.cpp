// T.C = O(α)     S.C = O(n)

class Solution {
public:
    int find(vector<int>& parent, vector<int>& rank, int i) 
    {
        if(parent[i] != i)
            parent[i] = find(parent, rank, parent[i]);
        
        return parent[i];
    }
    
    void Union(vector<int>& parent, vector<int>& rank, int i, int j) 
    {
        int root_i = find(parent, rank, i);
        int root_j = find(parent, rank, j);
        
        // updating the owner
        if(root_i != root_j) 
        {
            if(rank[root_i] > rank[root_j]) 
            {
                parent[root_j] = root_i;
            } 
            else if(rank[root_i] < rank[root_j]) 
            {
                parent[root_i] = root_j;
            } 
            else 
            {
                parent[root_j] = root_i;
            }
        }
    }
    
    int removeStones(vector<vector<int>>& stones) 
    {
        int n = stones.size();

        vector<int> parent(n);
        vector<int> rank(n);
        
        for(int i = 0; i < n; i++) 
        {
            // initializing the vector with owners
            parent[i] = i;
            rank[i] = 1;
        }
        
        for(int i = 0; i < n; i++) 
        {
            for(int j = i+1; j < n; j++) 
            {
                // checking for matching row or column
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    // grouping the similar ones
                    Union(parent, rank, i, j);
            }
        }
        
        int groups = 0;
        for(int i = 0; i < n; i++) 
        {
            if(parent[i] == i) 
                groups++;
        }
        
        return n - groups;
    }
};