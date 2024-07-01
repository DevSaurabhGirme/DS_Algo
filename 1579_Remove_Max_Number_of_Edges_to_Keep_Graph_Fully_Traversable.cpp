class Solution {
public:
    class DSU{
        public :
            vector<int> parent;
            vector<int> rank;

            int comps;

            DSU(int n)
            {
                parent.resize(n+1);
                
                // initailize parent
                for(int i = 1; i <= n; i++)
                {
                    parent[i] = i;
                }

                rank.resize(n+1);
                comps = n;
            }

            int find(int x)
            {
                if(x == parent[x])
                {
                    return x;
                }

                return parent[x] = find(parent[x]);
            }

            void Union(int x, int y)
            {
                int x_parent = find(x);
                int y_parent = find(y);
            
                if(x_parent == y_parent)
                {
                    return;
                }

                if(rank[x_parent] > rank[y_parent])
                {
                    parent[y_parent] = x_parent;
                }
                else if(rank[x_parent] < rank[y_parent])
                {
                    parent[x_parent] = y_parent;
                }
                else
                {
                    parent[x_parent] = y_parent;
                    rank[y_parent]++;
                }

                comps--;
            }

            bool isSingleComps()
            {
                return comps == 1;
            }
    };

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) 
    {
        DSU Alice(n);
        DSU Bob(n);

        auto lambda = [](vector<int>& vec1, vector<int>& vec2)
        {
            return vec1[0] > vec2[0];
        };

        sort(begin(edges), end(edges), lambda);

        int edgeCnt = 0;

        for(auto &vec : edges)
        {
            int type = vec[0];
            int u = vec[1];
            int v = vec[2];

            if(type == 3)
            {
                bool addEdge = false;

                // alice
                if(Alice.find(u) != Alice.find(v))
                {
                    Alice.Union(u, v);
                    addEdge = true;
                }
            
                // Bob
                if(Bob.find(u) != Bob.find(v))
                {
                    Bob.Union(u, v);
                    addEdge = true;
                }

                if(addEdge == true)
                {
                    edgeCnt++;
                }
            }
            else if(type == 2)
            {
                if(Bob.find(u) != Bob.find(v))
                {
                    Bob.Union(u, v);
                    edgeCnt++;
                }
            }
            else
            {
                if(Alice.find(u) != Alice.find(v))
                {
                    Alice.Union(u, v);
                    edgeCnt++;
                }              
            }
        }
        if(Alice.isSingleComps() == true && Bob.isSingleComps() == true)
        {
            return edges.size() - edgeCnt;
        }

        return -1;
    }
};