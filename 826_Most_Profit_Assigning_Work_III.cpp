// T.C = O(nlogn + mlogn)

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) 
    {
        int n = difficulty.size();
        int m = worker.size();

        // pair of difficulty and profit
        vector<pair<int, int>> reward;     
    
        for(int i = 0; i < n; i++)
        {
            reward.push_back({difficulty[i], profit[i]});
        }
        
        sort(begin(reward), end(reward));

        sort(begin(worker), end(worker));

        int totalProfit = 0;
        int j = 0;
        int maxProfit = 0;

        for(int i = 0; i < m; i++)
        {
            while(worker[i] >= reward[j].first)
            {
                maxProfit = max(maxProfit, reward[j].second);
                j++;
            }

            totalProfit += maxProfit;
        }

        return totalProfit;
    }
};