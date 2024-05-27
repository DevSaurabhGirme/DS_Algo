// T.C = O(log(n)) + nlog(n)    S.C = O(1)

class Solution {
public:
    int specialArray(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int x_low = 0;
        int x_high = n;

        while(x_low <= x_high)
        {
            int mid_x = x_low + (x_high - x_low) / 2;

            // returns iterator pointing to first integer >= x
            int Idx = lower_bound(begin(nums), end(nums), mid_x) - begin(nums);

            int count = n - Idx;

            if(count == mid_x)
            {
                return mid_x;
            }
            else if(count > mid_x)
            {
                x_low = mid_x + 1;
            }
            else
            {
                x_high = mid_x - 1;
            }
        }
        return -1;
    }
};