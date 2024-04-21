class Solution {
public:
    bool DFS(unordered_map<int, vector<int>>& graphMap, int S, int D, vector<bool>& visited)
    {
        if(S == D)
        {
            return true;
        }
        if(visited[S] == true)
        {
            return false;
        }
        // marking as visited
        visited[S] = true;

        // retrieving eac source node from the map  
        for(auto &node : graphMap[S])
        {
            // recursive call
            if(DFS(graphMap, node, D, visited) == true)
            {
                // path detected
                return true;
            }
        }
        // no path exists
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        // map for building the graph
        unordered_map<int, vector<int>> graphMap;

        for(vector<int> &edge : edges)
        {
            // retrieving each edge from edges vector
            int u = edge[0];
            int v = edge[1];

            // inserting the bi-directional edges into map
            graphMap[u].push_back(v);
            graphMap[v].push_back(u);
        }

        // vector to mark as visited for each node
        vector<bool> visited(n, false);

        // primary call
        return DFS(graphMap, source, destination, visited);
    }
};