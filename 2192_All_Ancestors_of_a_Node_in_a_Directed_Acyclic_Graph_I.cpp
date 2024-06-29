class Solution {
public:
    void DFS(int ancestor, unordered_map<int, vector<int>>& paths, int curr_node,vector<vector<int>>& ances)
    {
        for(int& nhb : paths[curr_node])
        {
            if(ances[nhb].empty() || ances[nhb].back() != ancestor)
            {
                ances[nhb].push_back(ancestor);
                DFS(ancestor, paths, nhb, ances);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> ances(n);
        // map for graph
        unordered_map<int, vector<int>> paths;

        for(vector<int>& edge : edges)
        {
            int n0 = edge[0];
            int n1 = edge[1];

            // edge between n0 and n1
            paths[n0].push_back(n1);
        }    

        for(int i = 0; i < n; i++)
        {
            int ancestor = i;

            DFS(ancestor, paths, i, ances);
        }

        return ances;
    }
};