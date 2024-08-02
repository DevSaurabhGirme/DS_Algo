// T.C = O(n)   S.C = O(1)

class Solution {
public:
    int minSwaps(vector<int>& nums) 
    {
        int n = nums.size();

        // total count of ones in the array
        int totalOnes = accumulate(begin(nums), end(nums), 0);

        int i = 0;
        int j = 0;

        int curr_ones = 0;
        int max_count = 0;

        while(j < 2*n)
        {
            if(nums[j%n] == 1)
            {
                curr_ones++;
            }

            // shrink window
            if(j-i+1 > totalOnes)
            {
                curr_ones -= nums[i%n];
                i++;
            }

            max_count = max(max_count, curr_ones);
            j++;
        }

        return totalOnes - max_count;
    }
};