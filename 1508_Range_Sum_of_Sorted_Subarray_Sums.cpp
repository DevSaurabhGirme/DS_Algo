class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int sub_sum[n * (n + 1) / 2];
        
        for (int i = 0, Idx = 0; i < n; ++i) 
        {
            int sum = 0;
            for (int j = i; j < n; j++,Idx++) 
            {
                sum += nums[j];
                sub_sum[Idx] = sum;
            }
        }

        sort(sub_sum, sub_sum + n * (n + 1) / 2);
        
        int Sum = 0;

        const int MOD = 1e9 + 7;
        
        for (int i = left - 1; i < right; i++) 
        {
            Sum = (Sum + sub_sum[i]) % MOD;
        }

        return Sum;
    }
};