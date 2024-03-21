// optimized using STL's functions applicable for vectors 

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();

        int cheapBuy = INT_MAX;
        int max_profit = 0;
        
        for(int i = 0; i < n; i++)
        {
            // finding cheapest buy-price
            cheapBuy = min(cheapBuy, prices[i]);
            // calculate maximum profit using above cheapest buy-price
            max_profit = max(max_profit, prices[i] - cheapBuy);
        }

        return max_profit;
    }
};