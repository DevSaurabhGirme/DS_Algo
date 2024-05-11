// T.C = O(nlogn + klogk + (n*logk))
 
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

        priority_queue<int, vector<int>> pq;

        int sum_quality = 0;
        for(int i = 0; i < k; i++)
        {
            pq.push(worker_ratio[i].second);
            sum_quality = sum_quality + worker_ratio[i].second;
        }

        double manRatio = worker_ratio[k-1].first;

        result = manRatio * sum_quality;

        // considering manager from k-th worker and further
        for(int man = k; man < n; man++)
        {
            // worker ratio already calculated
            double manRatio = worker_ratio[man].first;

            pq.push(worker_ratio[man].second);
            // ading new managers quality to previously calculated sum of qualities
            sum_quality = sum_quality + worker_ratio[man].second;

            if(pq.size() > k)
            {
                sum_quality -= pq.top();
                pq.pop(); 
            }

            result = min(result, manRatio * sum_quality);
        }
        return result;
    }
    
};