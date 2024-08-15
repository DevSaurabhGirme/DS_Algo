// T.C = O(3nlog(high))

class Solution {
public:
    int getPairCount(vector<int>& nums, int mid)
    {
        int i = 0; 
        int j = 1;

        int n = nums.size();
        int pairCnt = 0;

        while(j < n)
        {
            // shrink the window
            while(nums[j] - nums[i] > mid)
            {
                i++;
            }

            // collecting pairs
            pairCnt += (j-i);
            j++;
        }

        return pairCnt;
    }

    int smallestDistancePair(vector<int>& nums, int k) 
    {   
        int n = nums.size();
        
        sort(begin(nums), end(nums));

        int low = 0;
        int high = nums[n-1]- nums[0];

        int result = 0;

        while(low <= high)
        {
            int mid = low + (high-low)/2;

            int pairCount = getPairCount(nums, mid);

            if(pairCount < k)
            {
                low = mid + 1;
            }
            else
            {
                result = mid; // storing our possible result
                high = mid-1;
            }
        }

        return result;
    }
};