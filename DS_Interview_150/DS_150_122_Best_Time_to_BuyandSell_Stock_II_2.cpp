class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int profit = 0;
        int maxProfit = 0;

        // map to store day and profit made on this day
        unordered_map<int,int> unmap;

        // iterate through prices,calculate and insert profit made on each day into the map
        for(int i = 1; i < n; i++)
        {
            profit = prices[i] - prices[i-1];
            unmap.insert({i, profit});
        }

        // iterate through the map and find positive profit and add it up to maximum profit variable
        for (auto it = unmap.begin(); it != unmap.end(); ++it) 
        {   
            // if(profit >= 0)
            if((it->second) >= 0)
            {   
                maxProfit = maxProfit + it->second;
            }
        }

        return maxProfit;
    }
};