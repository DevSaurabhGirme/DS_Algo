// T.C = O(V+E)     S.C = O(V+E)

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) 
    {
        // building graph
        // 11 -> {... , 9}
        unordered_map<int, vector<int>> adj;    

        // to store indegree and outdegree
        // key  -> value
        // node -> indegree / outdegree value
        unordered_map<int, int> in, out;

        for(auto &edge : pairs)
        {
            int u = edge[0];
            int v = edge[1];

            // forming an edge
            adj[u].push_back(v);
            out[u]++;
            in[v]++;
        }

        // finding start node of te euler path
        
        int startNode = pairs[0][1];
        for(auto &it : adj)
        {
            int node = it.first;
            // starting node for traversal found
            if(out[node] - in[node] == 1)
            {
                startNode = node;
                break;
            }
        }

        // stores the Euler's path
        vector<int> path;
        // to store nodes for DFS purpose
        stack<int> stk;

        stk.push(startNode);

        while(!stk.empty())
        {
            int currNode = stk.top();
            if(!adj[currNode].empty())
            {
                int nbr = adj[currNode].back();
                adj[currNode].pop_back();
                stk.push(nbr);
            }
            // no more neigbors
            else
            {
                path.push_back(currNode);
                stk.pop();
            }
        }

        // reversing vector for result
        reverse(path.begin(), path.end());

        vector<vector<int>> result;

        for(int i = 0; i < path.size()-1; i++)
        {
            result.push_back({path[i], path[i+1]});
        }

        return result;
    }
};