class Solution {
public:

    // global variable to store n1,n2,n3
    vector<vector<int>> triplets;

    void twoSum(vector<int>& nums, int newTarget, int i, int j)
    {
        while(i < j)
        {
            if(nums[i] + nums[j] > target)
            {
                j--;
            }
            else if(nums[i] + nums[j] < target)
            {
                i++;
            }
            else
            {   // target found
                
                // avoiding duplicates
                while(i < j && nums[i] == nums[i+1])
                {
                    i++;
                }

                while(i < j && nums[j] == nums[j-1])
                {
                    j--;
                }

                triplets.push_back({-newTarget, nums[i], nums[j]});

                i++;
                j--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n = nums.size();

        // no triplets to be found
        if(n < 3)
        {
            return {};
        }

        // sorting in ascending order
        sort(begin(nums), end(nums));

        // n1+n2+n3 = 0
        // n2+n3 = -n1

        // deciding new target i.e n1
        for(int i = 0; i < n-2; i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }

            int n1        =  nums[i];
            int newTarget = -n1;

            // call to our regular 2sum business logic
            twoSum(nums, newTarget, i+1, n-1);
        }

        return tripets;
    }
};