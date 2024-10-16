// T.C = O(nlogn)   S.C = O(n)

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> ends_heap;

        for(vector<int>& interval : intervals)
        {
            int curr_start = interval[0];
            int curr_end = interval[1];

            // no intersection
            // hence into same group
            if(!ends_heap.empty() && curr_start > ends_heap.top())
            {
                ends_heap.pop();
            }

            ends_heap.push(curr_end);
        }

        return ends_heap.size();
    }
};