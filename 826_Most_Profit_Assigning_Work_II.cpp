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

        // finding maximum profit until every index
        for(int i = 1; i < reward.size(); i++) 
        {
            reward[i].second = max(reward[i].second, reward[i-1].second);
        }

        int totalProfit = 0;
        for(int i = 0; i < m; i++)
        {
            int workerDifflvl = worker[i];

            int l = 0, r = reward.size()-1;
            int maxProfit = 0;

            while(l <= r)
            {
                int mid = l+(r-l)/2;
                if(reward[mid].first <= workerDifflvl)
                {
                    maxProfit = max(maxProfit, reward[mid].second);
                    l = mid+1; // in search of more profit
                }
                else
                {
                    r = mid-1;
                }
            }
            
            totalProfit += maxProfit;
        }

        return totalProfit;
    }
};