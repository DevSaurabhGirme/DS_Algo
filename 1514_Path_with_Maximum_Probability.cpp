// T.C = O(E logv)  S.C = O(n)

class Solution {
public:
    typedef pair<double, int> P;

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) 
    {
        // to store node and its destinations
        unordered_map<int, vector<pair<int, double>>> adjList;    

        vector<double> result(n, 0);

        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            double probab = succProb[i];

            // connecting edges
            adjList[u].push_back({v, probab});
            adjList[v].push_back({u, probab});
        }

        priority_queue<P> max_heap;

        // probability to reach itself
        result[start_node] = 1.0;
        max_heap.push({1.0, start_node});

        while(!max_heap.empty())
        {
            int curr_node = max_heap.top().second;
            double curr_prob = max_heap.top().first;
            max_heap.pop();

            // current node and probability
            for(auto& pair : adjList[curr_node])
            {
                double adjListProb = pair.second;
                int adjListNode = pair.first;

                if(result[adjListNode] < curr_prob * adjListProb)
                {
                    result[adjListNode] = curr_prob * adjListProb;

                    max_heap.push({result[adjListNode], adjListNode});
                }
            }
        }

        return result[end_node];
    }
};