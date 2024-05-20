class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) 
    {
        long int sum = 0;

        // number of nodes XOR performed on
        int count = 0;
    
        int minLoss = INT_MAX;

        for(long int num : nums)
        {
            // if value increases after performing XOR
            if((num ^ k) > num)
            {
                count++;    // xor performed on a node
                sum = sum + (num ^ k);
            }
            else
            {
                sum = sum + num;
            }

            minLoss = min((long int)minLoss, abs(num - (num ^ k)));
        }

        // if count is even
        if(count % 2 == 0)
        {
            return sum;
        }

        return sum - minLoss;
    }
};