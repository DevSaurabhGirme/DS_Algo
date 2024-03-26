class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int n = nums.size();
        bool contains1 = false;

        for(int i = 0; i < n; i++)
        {
            // check if 1 is already present or not
            if(nums[i] == 1)
            {
                contains1 = true;
            }

            // if 0 < nums[i] > n then it will generate indexoutofbound exception
            if(nums[i] <= 0 || nums[i] > n)
            {
                // we can deal with integers within [1,n]
                nums[i] = 1;
            }
        }

        // if the nums array doesn't contain 1 in it then it's definitely our smallest missing integer
        if(contains1 == false)
        {
            return 1;
        }

        int num = 0, idx = 0;

        // using numbers as index
        for(int i = 0; i < n; i++)
        {
            num = abs(nums[i]);
            idx = num - 1;

            if(nums[idx] < 0)
            {
                continue;
            }
            else
            {
                nums[idx] = -1 * nums[idx];
            }
        }

        // iterate through nums again and return 1st positive integer's proceeding index
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > 0)
            {
                return i+1;
            }
        }
    return n+1;

    }
};