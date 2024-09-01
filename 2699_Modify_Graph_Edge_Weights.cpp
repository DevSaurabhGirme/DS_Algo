class Solution {
public:
    typedef long long ll;
    long int LV = 2e9;
    typedef pair<long, long> P;

    ll DijAlgo( vector<vector<int>>& edges, int n, int source, int destination)
    {
        // building graph

        unordered_map<ll, vector<pair<ll, ll>>> adj;
    
        for(vector<int>& edge : edges)
        {
            if(edge[2] != -1)
            {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                adj[u].push_back({v, wt});
                adj[v].push_back({u, wt});
            }
        }

        priority_queue<P, vector<P>, greater<P>> min_h;
        
        // to maintain shortest distance from source node
        vector<ll> result(n, INT_MAX);
        vector<bool> visited(n, false);

        // distance from source to source
        result[source] = 0;

        min_h.push({0, source});

        while(!min_h.empty())
        {
            ll currDist = min_h.top().first;
            ll currNode = min_h.top().second;

            min_h.pop();

            if(visited[currNode] == true)
            {
                continue;
            }
            // marking as visited
            visited[currNode] = true;
        
            for(auto& [nbr, wt] : adj[currNode])
            {
                if(result[nbr] > currDist + wt)
                {
                    result[nbr] = currDist + wt;
                    min_h.push({result[nbr], nbr});   
                }
            }
        }
        return result[destination];
        
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) 
    {
        ll currST = DijAlgo(edges, n, source, destination);

        if(currST < target)
        {
            return {};
        }

        // if shortest Distance matches the target
        bool targetMatch = (currST == target);
        if(targetMatch == true)
        {
            for(vector<int>& edge : edges)
            {
                // reassigning all remaining -ve weights the large value
                // to maintain the currST
                if(edge[2] == -1)
                {
                    edge[2] = LV;
                }
            }

            return edges;
        }    
    
        for(vector<int>& edge : edges)
        {
            if(edge[2] == -1)
            {
                edge[2] = (targetMatch == true) ? LV : 1;

                if(targetMatch == false)
                {
                    ll newSD = DijAlgo(edges, n, source, destination);
                   
                    if(newSD <= target)
                    {
                        targetMatch = true;
                        edge[2] += (target - newSD);
                    }
                }
            }
        }

        if(targetMatch == false)
        {
            return {};
        }
        return edges;
    }
};