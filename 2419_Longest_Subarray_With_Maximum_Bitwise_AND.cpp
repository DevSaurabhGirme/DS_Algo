// T.C = O(n)   S.C = O(1)

class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int maxVal = nums[0];
        int result = 0;
        int curr_length = 0;    
    
        for(int &num : nums)
        {
            if(num > maxVal)
            {
                maxVal = num;

                result = 0;
                curr_length = 0;
            }

            // latest largest number found
            if(num == maxVal)
            {
                curr_length++;
            }
            else
            {
                curr_length = 0;
            }

            result = max(result, curr_length);
        }

        return result;
    }
};