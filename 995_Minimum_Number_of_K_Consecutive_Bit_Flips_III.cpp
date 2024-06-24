// T.C = O(n)   S.C = O(k)

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) 
    {
        int n = nums.size();

        int  minflips = 0;

        int flipCntFor_i = 0;

        deque<int> flip;

        for(int i = 0; i < n; i++)
        {
            // current index out of reach of 'k' size window and 
            // if already flipped at i-k index
            if(i >= k)
            {
                // flipped = 1 unflipped = 0
                flipCntFor_i -= flip.front();
                flip.pop_front();
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
                // flipped
                flip.push_back(1);
            }
            else
            {
                // unflipped
                flip.push_back(0);
            }
        
        }

        return minflips;    
    }
};