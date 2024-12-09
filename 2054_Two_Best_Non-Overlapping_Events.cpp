// T.C = O(nlogn)   S.C = O(n)

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) 
    {
        // Sort events according to their starting time
        sort(events.begin(), events.end());

        // min heap to store current event's end and its value
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap;
        
        // maximum value among to non-overlapping events
        int maxVal = 0;
        // final value sum
        int maxSum = 0;

        for(auto& event : events) 
        {
            int start = event[0];
            int end = event[1];
            int value = event[2];

            // Remove events that end before the current event's start time
            while(!min_heap.empty() && min_heap.top().first < start) 
            {
                maxVal = max(maxVal, min_heap.top().second);
                min_heap.pop();
            }

            // update the final maximum sum of values
            maxSum = max(maxSum, maxVal + value);

            // Add the current event's end time and its vaue to heap
            min_heap.push({end, value});
        }

        return maxSum;
    }
};