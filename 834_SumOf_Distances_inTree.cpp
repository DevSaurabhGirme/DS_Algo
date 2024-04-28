class Solution {
public:
    long root_result = 0;
    vector<int> child_count;
    int total_nodes = 0;

    // function to calculate:
    // sum of distances from root to every other node //
    // and total number of children including the node itself //
    int DFS_Root(unordered_map<int, vector<int>> &adj, int curr_node, int prev_node, int curr_dist)
    {
        // total count of children initialized to 1
        // 1 being root/parent itself
        int total_count = 1;

        // calculating distance from curr_node/parent/root to other nodes
        root_result = root_result + curr_dist;
    
        // traversing to count child nodes
        for(int &child : adj[curr_node])
        {
            if(child == prev_node)
            {
                continue;
            }
            //                             recursive call to calculate children of child
            total_count = total_count + DFS_Root(adj, child, curr_node, curr_dist+1); 
        }

        // count of children including crr_node
        child_count[curr_node] = total_count;

        return total_count;
    }

    // populating the vector result //
    void DFS(unordered_map<int, vector<int>> &adj, int parent_node, int prev_node, vector<int> &result)
    {
        for(int &child : adj[parent_node])
        {
            if(child == prev_node)
            {
                continue;
            }

            result[child] = result[parent_node] + (total_nodes - child_count[child]) - child_count[child];
        
            DFS(adj, child, parent_node, result);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) 
    {
        // building our graph
        unordered_map<int, vector<int>> adj;

        total_nodes = n;

        child_count.resize(n, 0);
        // inserting elements of our graph
        for(vector<int> &vec : edges)
        {
            // bi-directional
            int u = vec[0];
            int v = vec[1];

            // u -> v
            adj[u].push_back(v);
            // v -> u
            adj[v].push_back(u);
        }

        root_result = 0;

        //      (graph,parent,previous node,distance from root/depth)
        DFS_Root(adj  ,   0  ,   -1        , 0);
  
        vector<int> result(n, 0);

        // sum of distances of 0th node
        result[0] = root_result;

        // call to populate the result vector
        DFS(adj, 0, -1, result);

        return result; 
    }
};