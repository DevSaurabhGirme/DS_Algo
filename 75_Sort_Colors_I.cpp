// S.C = O(1)   T.C = O(n)

class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int n = nums.size();

        int l = 0;
        int m = 0;
        int r = n-1;

        while(m <= r)
        {
            if(nums[m] == 0)
            {
                int temp = nums[l];
                nums[l] = nums[m];
                nums[m] = temp;
                
                l++;
                m++;
            }
            else if(nums[m] == 1)
            {
                m++;
            }
            else
            {
                int temp = nums[m];
                nums[m] = nums[r];
                nums[r] = temp;

                r--;
            }
            
        }

        return;
    }
};