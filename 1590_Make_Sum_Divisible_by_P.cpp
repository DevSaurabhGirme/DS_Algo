// T.C = O(n)   S.C = O(n)

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) 
    {
        int n = nums.size();
        int sum = 0;

        // cumulative sum with modulus
        for(int &num : nums) 
        {
            sum = (sum + num) % p;
        }

        // value causing issue
        int target = sum % p;

        if(target == 0) 
        {
            return 0;
        }

        // to store prefix sum and its index
        unordered_map<int, int> mp;

        int curr_sum = 0;
        // initializing the map
        mp[0] = -1;

        // length of smallest subarray
        int len = n;

        for(int j = 0; j < n; j++) 
        {
            curr_sum = (curr_sum + nums[j]) % p;
            int remain = (curr_sum - target + p) % p;
            // culprit found
            if(mp.find(remain) != mp.end()) 
            {
                len = min(len, j - mp[remain]);
            }

            mp[curr_sum] = j;
        }

        return len == n ? -1 : len;

    }
};