// T.C = O(n)   S.C = O(1)

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) 
    {
        int n = nums.size();

        int  minflips = 0;

        int flipCntFor_i = 0;

        for(int i = 0; i < n; i++)
        {
            // current index out of reach of 'k' size window and 
            // if already flipped at i-k index
            if(i >= k && nums[i-k] == -1)
            {
                flipCntFor_i--;
            }

            if(flipCntFor_i % 2 == nums[i])
            {
                // going out of bound 
                if(i + k > n)
                {
                    return -1;
                }

                // increment flip count for current index
                flipCntFor_i++;
                // increment result
                minflips++;
                // mark as fliped
                nums[i] = -1;
            }
        
        }

        return minflips;    
    }
};