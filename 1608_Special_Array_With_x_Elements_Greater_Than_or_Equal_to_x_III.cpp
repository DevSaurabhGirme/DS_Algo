class Solution {
public:
    int specialArray(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // to keep count of number of integers >= nums[i]
        vector<int> count(n+1);

        for(int i = 0; i < n; i++)
        {
            int num = nums[i];

            count[min(n, num)]++;
        }

        // calculating prefix sum 
        int count_sum = 0;
        for(int x = n; x >= 0; x--)
        {
            count_sum += count[x];

            // looking for x on the fly
            if(x == count_sum)
            {
                return x;
            }
        }
        return -1;
    }
};