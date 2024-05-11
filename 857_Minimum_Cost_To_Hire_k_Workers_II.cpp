// T.C = O(n+nlogn * (n + nlogk))
// TLE

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& exp_wage, int k) 
    {
        int n = quality.size();

        double result = DBL_MAX;

        // calculating worker's ratio and storing along with its quality  
        vector<pair<double, int>> worker_ratio(n);
        for(int worker = 0; worker < n; worker++)
        {
            worker_ratio[worker] = make_pair((double)exp_wage[worker] / quality[worker], quality[worker]);
        }

        sort(begin(worker_ratio), end(worker_ratio));

        // considering manager as (k-1)th worker and further
        for(int man = k - 1; man < n; man++)
        {
            // worker ratio already calculated
            double man_ratio = worker_ratio[man].first;
        
            // group for current worker as ma nager
            vector<double> paid_group;
            for(int worker = 0; worker <= man; worker++)
            {
                double worker_wage = man_ratio * worker_ratio[worker].second;
                paid_group.push_back(worker_wage);
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