// T.C = O(n)   S.C = O(1)

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        int n = nums.size();

        // count of odd numbers found till current index
        int prevCnt = 0;
        int result = 0;
        int oddCnt = 0;
        
        int i = 0;
        int j = 0;

        while(j < n)
        {
            if(nums[j] % 2 != 0)
            {
                oddCnt++;
                // reset the count for further iterations
                prevCnt = 0;
            }

            while(oddCnt == k)
            {
                // got a valid subarray so increment the prevCnt
                prevCnt++;

                // shrinking the window
                if(nums[i] % 2 == 1)
                {
                    oddCnt--;
                }
                i++;
            }

            result += prevCnt;
            j++;
        }

        return result;
    }
};