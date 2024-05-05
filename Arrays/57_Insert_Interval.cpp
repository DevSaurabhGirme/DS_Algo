class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        // resultant vector
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();

        while(i < n)
        {
            // existing intervals end is smaller than new intervals' start
            if(intervals[i][1] < newInterval[0])
            {
                // readily place it in the result vector 
                result.push_back(intervals[i]);
            }
            // existing intervals start is greater than new intervals' end
            else if(intervals[i][0] > newInterval[1])
            {
                // found the position to insert new interval hence we break
                break;
            }
            else
            {
                // merging new interval into existing interval
                newInterval[0] = min(newInterval[0] , intervals[i][0]);
                newInterval[1] = max(newInterval[1] , intervals[i][1]);
            }
            i++;
        
        }

        // add the merged/'new interval' into the result vector after processing and merging it with
        // overlapping intervals from the input intervals.
        result.push_back(newInterval);

        // append the remaining intervals vector's elements in the result vector
        while(i < n)
        {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};