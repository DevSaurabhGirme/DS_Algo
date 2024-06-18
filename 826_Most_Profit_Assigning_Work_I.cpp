// T.C = O(nlog(n) * mlog(m))

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) 
    {
        int n = difficulty.size();
        int m = worker.size();

        // pair of difficulty and profit
        // max_heap
        priority_queue<pair<int, int>> reward;     
    
        for(int i = 0; i < n; i++)
        {
            int diff = difficulty[i];
            int prof = profit[i];

            reward.push({prof, diff});
        }

        // sorting worker array descending
        sort(begin(worker), end(worker), greater<int>());
    
        int totalProfit = 0;

        int i = 0;
        while (i < m && !reward.empty())
        {
            // job difficulty more then worker's capacity
            if(reward.top().second > worker[i])
            {
                reward.pop();
            }
            else
            {
                // job doable by worker
                totalProfit += reward.top().first;
                i++;
            }
        }
        
        return totalProfit;
    }
};