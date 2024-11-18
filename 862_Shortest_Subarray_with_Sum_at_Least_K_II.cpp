// T.C = O(n)   S.C = O(n)

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) 
    {
        int n = nums.size();

        // minimum length subarray 
        int minLen = INT_MAX;

        vector<long int> prefixSum(n+1,0);

        // calculating prefix sum
        for(int i = 0; i < n; i++) 
        {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }

        // to store indices
        deque<int> deq;

        for(int i = 0; i <= n; i++)
        {
            while(!deq.empty() && prefixSum[i] - prefixSum[deq.front()] >= k)
            {
                // updating minlen
                minLen = min(minLen, i - deq.front());
                // delete this index to replace with a greater one for length to become more small
                deq.pop_front();
            }

            while(!deq.empty() && prefixSum[i] <= prefixSum[deq.back()])
            {
                // delete this index as any subarray starting after deq.back() index
                // and ending at i will not form a smaller or valid subarray than one starting at 𝑖
                deq.pop_back();
            }

            deq.push_back(i);
        }

        if(minLen == INT_MAX)
        {
            return -1;
        }

        return minLen;
    }
};