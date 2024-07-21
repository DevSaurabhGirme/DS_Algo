// T.C = O(k^2)     S.C = O(k^2)

class Solution {
public:
    void DFS(int u, vector<int>& visited, unordered_map<int, vector<int>>& graph, stack<int>& stk, bool& isCycle)
    {
        visited[u] = 1;

        for(int &v : graph[u])
        {
            if(visited[v] == 0)
            {
                DFS(v, visited, graph, stk, isCycle);
            }
            else if(visited[v] == 1)
            {
                isCycle = true;
                return;
            }
        }

        visited[u] = 2;
        stk.push(u);
    }

    vector<int> topoSort(vector<vector<int>>& edges, int& n)
    {
        // graph
        unordered_map<int, vector<int>> graph;

        // topological order
        vector<int> order;

        for(vector<int>& edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            // unidrected edge formed
            graph[u].push_back(v);
        }

            // visited[i] = 0 // not visited
            // visited[i] = 1 // DFS is being performed
            // visited[i] = 2 // visited
            vector<int> visited(n+1, 0);
            
            // stack to store edge and its neighbors
            stack<int> stk;

            bool isCycle = false;
            for(int i = 1; i <= n; i++)
            {
                if(visited[i] == 0)
                {
                    DFS(i, visited, graph, stk, isCycle);
                    if(isCycle == true)
                    {
                        return {};
                    }
                }
            }

            while(!stk.empty())
            {
                order.push_back(stk.top());
                stk.pop();
            }
            return order;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) 
    {
        vector<int> topo_row = topoSort(rowConditions, k);
        vector<int> topo_col = topoSort(colConditions, k);

        // cycle detected 
        if(topo_row.empty() || topo_col.empty())
        {
            return {};
        }

        vector<vector<int>> matrix(k, vector<int>(k, 0));

        for(int i = 0; i < k; i++)
        {
            for(int j = 0; j < k; j++)
            {
                if(topo_row[i] == topo_col[j])
                {
                    matrix[i][j] = topo_row[i];
                }
            }
        }

        return matrix;
    }
};