class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        
        vector<vector<int>> result;

        // sorting based of start of the interval
        sort(intervals.begin(), intervals.end());

        // insert the first interval from the intervals
        result.push_back(intervals[0]);

        if (n == 1) return result;

        for(int i = 1; i < n; i++)
        {
            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];

            // overlapping intervals
            if(curr_start <= result.back()[1])
            {
                result.back()[1] = max(result.back()[1], curr_end);
            }
            // no overlapping intervals
            else
            {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};
