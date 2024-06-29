class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) 
    {
        // n = total number of cities
        vector<int> degree(n,0);

        for(auto &road : roads)
        {
            int c1 = road[0];
            int c2 = road[1];

            degree[c1]++;
            degree[c2]++;
        }
        sort(begin(degree), end(degree));

        long int val = 1;
        long int sum = 0;

        for(int i = 0; i < n; i++)
        {
            sum = sum + (degree[i] * val);
            val++;
        }

        return sum;
    }
};