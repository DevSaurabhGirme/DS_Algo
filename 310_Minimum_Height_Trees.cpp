// T.C = O(V+E)     S.C = O(V+E)

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        if(n == 1)
        {
            return {0};
        }

        // building the graph
        unordered_map<int, vector<int>> graph;    
    
        vector<int> indegree(n, 0);

        for(auto &edge :edges)
        {
            int u = edge[0];
            int v = edge[1];

            indegree[u]++;
            indegree[v]++;

            // edges are bi-directional
            // u <-> v 
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> MHT_roots;

        // to store leaf nodes
        queue<int> que;

        for(int i = 0; i < n; i++)
        {
            // check if the node is a leaf or not
            if(indegree[i] == 1)
            {
                // if yes then add it to the queue
                que.push(i);
            }
        }

        while(n > 2)
        {
            // leaf nodes to be ignored
            int size = que.size();

            // number of nodes to be processed
            n = n-size;

            while(size--)
            {
                int u = que.front();
                que.pop();

                // every neighbor of u in the graph
                for(int &v : graph[u])
                {
                    // since travelling towards centre of graph
                    // and the leaf being erased we decrement indegree of inner node
                    indegree[v]--;

                    // if v becomes a leaf node
                    if(indegree[v] == 1)
                    {
                        que.push(v);
                    }
                }
            }
        }
    
        while(!que.empty())
        {
            MHT_roots.push_back(que.front());
            que.pop();
        }

        return MHT_roots;
    }
};