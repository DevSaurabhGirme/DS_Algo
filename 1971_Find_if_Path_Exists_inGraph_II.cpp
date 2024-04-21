class Solution {
public:
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

        // queue to store our source nodes
        queue<int> que;
        que.push(source);

        // mark as visited
        visited[source] = true;

        while(!que.empty())
        {
            int s_node = que.front();
            que.pop();

            // path detected
            if(s_node == destination)
            {
                return true;
            }

            // explore possible destinations from s_node
            for(auto &dest : graphMap[s_node])
            {
                // not already visited
                if(!visited[dest])
                {
                    que.push(dest);
                    // mark it as visited
                    visited[dest] = true;
                }
            }
        }
        return false;
    
    }
};