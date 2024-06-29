// T.C = O(n)   S.C = O(n)

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) 
    {
        unordered_map<int, int> freq;

        int n = edges.size();

        for(const auto &edge : edges)
        {
            int n1 = edge[0];
            int n2 = edge[1];

            freq[n1]++;
            freq[n2]++;
        }

        for(auto& it : freq)
        {
            if(it.second == n)
            {
                return it.first;
            }
        }
        return -1;
    }
};