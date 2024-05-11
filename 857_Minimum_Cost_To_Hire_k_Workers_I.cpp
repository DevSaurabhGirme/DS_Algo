// T.C = O(n * (n + nlogk))
// TLE

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& exp_wage, int k) 
    {
        int n = quality.size();

        double result = DBL_MAX;

        // considering each worker as manager and calculate the cost for every other worker
        for(int man = 0; man < n; man++)
        {
            double man_ratio = (double)exp_wage[man] / quality[man];
        
            // group for current worker as ma nager
            vector<double> paid_group;
            for(int worker = 0; worker < n; worker++)
            {
                double worker_wage = man_ratio * quality[worker];

                if(worker_wage >= exp_wage[worker])
                {
                    paid_group.push_back(worker_wage);
                }
            }

            // group didn't form for current worker as manager
            if(paid_group.size() < k)
            {
                continue;
            }

            priority_queue<double, vector<double>> pq;
            double sum_wages = 0.0;
        
            for(double &wage : paid_group)
            {
                sum_wages = sum_wages + wage;
                pq.push(wage);

                if(pq.size() > k)
                {
                    sum_wages = sum_wages - pq.top();
                    pq.pop();
                }            
            }

            result = min(result, sum_wages);
        }
        return result;
    }
    
};