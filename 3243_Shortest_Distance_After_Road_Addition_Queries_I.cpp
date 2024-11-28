// T.C : O(q * (E log(V))   S.C = O(V+E)

class Solution {
public:
    int BFS(int n, unordered_map<int, vector<int>> adj) 
    {
        queue<int> que;

        // pushing source
        que.push(0);

        vector<bool> visited(n, false);
        visited[0] = true;

        int level = 0;
        
        while(!que.empty()) 
        {
            int size = que.size();
            
            // processing current level
            while(size != 0) 
            {
                int node = que.front();
                que.pop();
                
                // destination node found
                if(node == n-1) 
                {
                    return level;
                }

                // exploring neighours of current node
                for(int neighbor : adj[node]) 
                {
                    if(visited[neighbor] == false)
                    {
                        que.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
                size--;
            }

            level++;
        }

        // If destination node is unreachable
        return -1;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) 
    {
        // to store adjacency list
        unordered_map<int, vector<int>> adj;

        adj.clear();

        for (int i = 0; i <= n - 2; i++) 
        {
            adj[i].push_back(i + 1);
        }

        int k = queries.size();
        
        vector<int> answer(k);
        
        for (int i = 0; i < k; i++) 
        {
            adj[queries[i][0]].push_back(queries[i][1]);
            answer[i] = BFS(n, adj);
        }

        return answer;
    }
};