// T.C = O(n)   S.C = O(n)

class Solution {
public:
    int minSwaps(vector<int>& nums) 
    {
        int n = nums.size();

        vector<int> temp(2*n);

        // populating the temp array
        for(int i = 0; i < 2*n; i++)
        {
            temp[i] = nums[i%n];
        }

        // total count of ones in the array
        int totalOnes = accumulate(begin(nums), end(nums), 0);

        int i = 0;
        int j = 0;

        int curr_ones = 0;
        int max_count = 0;

        while(j < 2*n)
        {
            if(temp[j] == 1)
            {
                curr_ones++;
            }

            // shrink window
            if(j-i+1 > totalOnes)
            {
                curr_ones -= temp[i];
                i++;
            }

            max_count = max(max_count, curr_ones);
            j++;
        }

        return totalOnes - max_count;
    }
};