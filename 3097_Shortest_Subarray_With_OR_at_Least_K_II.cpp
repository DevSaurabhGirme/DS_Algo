// T.C = O(n)   S.C = O(n)

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) 
    {
        int n = nums.size();
        // vector to store setbits of every num
        vector<int> bitCount(32, 0);
    
        int currentOR = 0;
        int l = 0;
        int minlen = INT_MAX;
        
        // iterating nums
        for(int r = 0; r < n; r++) 
        {
            // calculating OR of the integers in nums
            currentOR = currentOR | nums[r];
            
            // updating the bitCount array
            for(int bit = 0; bit < 32; bit++) 
            {
                if((nums[r] & (1 << bit)) != 0) 
                {
                    // bit is set hence update
                    bitCount[bit]++;
                }
            }
            
            // shrinking the window
            while(l <= r && currentOR >= k) 
            {
                minlen = min(minlen, r - l + 1);

                // OR'ed value of current window
                int updatedOR = 0;
                
                // if bit is set update the OR for current window
                for(int bit = 0; bit < 32; bit++) 
                {
                    if((nums[l] & (1 << bit)) != 0) 
                    {
                        bitCount[bit]--;
                    }
                    if(bitCount[bit] > 0) 
                    {
                        updatedOR = updatedOR | (1 << bit);
                    }
                }

                // finally updating the OR for entire subarray
                currentOR = updatedOR;
                l++;
            }
        }
        
        if(minlen == INT_MAX)
        {
            return -1;
        }

        return minlen;
    }
};