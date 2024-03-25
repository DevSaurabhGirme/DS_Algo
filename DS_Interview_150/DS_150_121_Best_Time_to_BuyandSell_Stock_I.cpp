class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();

        // store running profit
        int currProfit = 0;
        // store maximum profit compared to profit
        int maxProfit = 0;

        // cheapest buy price of the stock
        // initiated to 1st price in the prices vector
        int cheapBuy = prices[0];

        int j = 0;
        
        // unable to calculate maxProfit
        if(n <= 1 || ((n == 2) && prices[0] > prices[1]))
        {
            return 0;
        }

        // maximum profit for default cheapest buy price 
        if((n == 2) && prices[0] < prices[1])
        {
            maxProfit = prices[1] - cheapBuy;
        }
        
        if(n > 2)
        {
            for(int i = 1; i < n; i++)
            {
                // found new cheapBuy: cheap price to buy the stock
                if(prices[i] < cheapBuy)
                {
                    cheapBuy = prices[i];
                    // travelled till last and found new cheapBuy
                    // but we already have a maximum profit
                    if((i == n-1) && prices[i] == cheapBuy)
                    {
                        // hence return it
                        return maxProfit;
                    }
                    // denotes next day of new buying day
                    j = i+1;
                    currProfit = prices[j] - cheapBuy;
                }
                else
                {
                    currProfit = prices[i] - cheapBuy;
                }            

                // finding maximum of current profit and maximum profit
                if(currProfit >= maxProfit)
                {
                    maxProfit = currProfit;
                }
            }
        }


        return maxProfit;
    }
};