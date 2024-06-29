// T.C = O(1)   S.C = O(1)

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) 
    {
        // comparing first egde with second edge for a common node

        if(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
        {
            return edges[0][0];
        }

        else
        {
            return edges[0][1];
        }

        return -1;
    }
};