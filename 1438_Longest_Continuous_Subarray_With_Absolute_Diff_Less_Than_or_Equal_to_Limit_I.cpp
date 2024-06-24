// T.C = O(nlogn)   S.C = O(2n)

class Solution {
public:
    typedef pair<int, int> P;

    int longestSubarray(vector<int>& nums, int limit) 
    {
        int n = nums.size();

        // <datatype, container type>
        priority_queue<P, vector<P>> max_pq;
        priority_queue<P, vector<P>, greater<P>> min_pq;    
    
        int i = 0;
        int j = 0;
        // maximum length of subarray found
        int max_len = 0;

        while(j < n)
        {
            // integer and its index
            max_pq.push({nums[j], j});
            min_pq.push({nums[j], j});

            while(max_pq.top().first - min_pq.top().first > limit)
            {
                // jump the index and shrinking the windowz
                i = min(max_pq.top().second, min_pq.top().second) + 1;

                // and pop the skipped intgers
                while(max_pq.top().second < i)
                {
                    max_pq.pop();
                }

                while(min_pq.top().second < i)
                {
                    min_pq.pop();
                }
            }

            // updating length o subarray
            max_len = max(max_len, j-i+1);
            j++;
        }

        return max_len;
    }
};