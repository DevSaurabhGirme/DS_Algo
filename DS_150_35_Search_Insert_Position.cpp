class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int n = nums.size();

        int left = 0;
        int right = n-1;

        int mid = 0;

        while(left < right)
        {
            mid = left + (right - left)/2;

            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                // new left pointer
                left = mid + 1;
            }
            else
            {
                // narrowing the search region to first half of array
                right = mid;
            }
        }

        if(nums[left] < target)
        {
            // target should be inserted after left
            return left+1;
        }
        else
        {
            // indicates that target should be inserted at this position
            // to maintain the sorted order of nums.
            return left;
        }
    }
};