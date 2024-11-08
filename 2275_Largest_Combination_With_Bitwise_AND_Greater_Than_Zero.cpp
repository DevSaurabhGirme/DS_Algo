// T.C = O(n)   S.C = O(1)

class Solution {
public:
    int largestCombination(vector<int>& candidates) 
    {
        int result = 0;
        
        // iterating i bits of every candidate
        for(int i = 0; i < 24; i++)
        {
            // count of candidates
            int iCnt = 0;

            for(auto candidate : candidates)
            {
                // performing AND operation at each bit of candidate
                // if answer is 1 bit is set
                if((candidate & (1 << i)) != 0)
                {
                    // hence increment count of candidates that can be used for combination
                    iCnt++;
                }
            }

            result = max(result, iCnt);
        }

        return result;
    }
};