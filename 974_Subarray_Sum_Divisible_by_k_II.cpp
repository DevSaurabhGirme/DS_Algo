// T.C = O(n^2)

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int n = nums.size();

        unordered_map<int, int> rm_count;    
        int sum = 0;

        // map initialized
        rm_count[0] = 1;

        // number of subarrays
        int count = 0;

        for(int i = 0; i < n; i++)
        {
            // cumulative sum
            sum += nums[i];

            int remainder = sum % k;

            // negative remainder
            if(remainder < 0)
            {
                remainder += k;
            }

            if(rm_count.find(remainder) != rm_count.end())
            {
                count += rm_count[remainder];
            }
            rm_count[remainder]++;
        }    
        
        return count;
    }
};