// T.C = O(nlogn)   S.C = O(1)

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) 
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int i = 0;
        int j = 0;

        int maxLen = 0;

        while(i < n)
        {
            while (j < n && nums[j] <= nums[i] + 2*k)
            {
                j++;
            }

            maxLen = max(maxLen, j-i);
            i++;
        }


        return maxLen;
    }
};