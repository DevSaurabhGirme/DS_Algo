// T.C = O(n)   S.C = O(n)

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) 
    {
        int n = nums.size();

        int  minflips = 0;

        int flipCntFor_i = 0;

        // vector cressponding to nums to mark whether integers are flipped or not
        vector<bool> isFlipped(n, false);

        for(int i = 0; i < n; i++)
        {
            // current index out of reach of 'k' size window and 
            // if already flipped at i-k index
            if(i >= k && isFlipped[i-k] == true)
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
                isFlipped[i] = true;
            }
        
        }

        return minflips;    
    }
};