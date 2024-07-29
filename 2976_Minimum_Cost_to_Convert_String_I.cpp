// T.C = O(26) or O(1+26^3)     S.C = O(26)

class Solution {
public:
    void FLW(vector<vector<long long>>& adjMat, vector<char>& original, vector<char>& changed, vector<int>& cost)
    {
        for(int i = 0; i < original.size(); i++)
        {
            int s = original[i] - 'a';
            int t = changed[i] - 'a';
        
            adjMat[s][t] = min(adjMat[s][t], (long long)cost[i]);
        
        }

        // Floyd algorithm
        // k is theintermediate node i.e
        // i -> k -> j (path or cost) 
        for(int k = 0; k < 26; k++)
        {
            for(int i = 0; i < 26; i++)
            {
                for(int j = 0; j < 26; j++)
                {
                    adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) 
    {
        vector<vector<long long>> adjMat(26, vector<long long>(26, INT_MAX));

        FLW(adjMat, original, changed, cost);

        long int ans = 0;

        for(int i = 0; i < source.length(); i++)
        {
            if(source[i] == target[i])
            {
                continue;
            }

            if(adjMat[source[i] - 'a'][target[i] - 'a'] == INT_MAX)
            {
                return -1;
            }

            ans += adjMat[source[i] - 'a'][target[i] - 'a'];
        }

        return ans; 
    }
};