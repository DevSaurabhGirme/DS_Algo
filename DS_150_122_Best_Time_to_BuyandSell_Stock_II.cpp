class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int profit = 0;

        for(int i = 1; i < n; i++)
        {
            // Check if the current price is greater than the previous price
            if(prices[i] > prices[i-1])
            {
                // If so, add the difference between the current price and the previous price to the profit
                profit = profit + (prices[i] - prices[i-1]);
            }
        }
        return profit;
    }
};