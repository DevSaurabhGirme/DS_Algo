// T.C = O(nlogn)   S.C = (1)

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();

        if(n <= 4)
        {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int minDiff = INT_MAX;

        // ignore or remove any 3 smallest or largest elements or part of both and
        // compute difference of remaining elements
        for(int i = 0; i < 4; i++)
        {
            //                          largest      - smallest
            minDiff = min(minDiff, nums[n - (3-i)-1] - nums[i]);
        }
        return minDiff;
    }
};