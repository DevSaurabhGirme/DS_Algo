// T.C = O(1)   S.C = O(1)

class Solution {
public:
    int minBitFlips(int start, int goal) 
    {
        int flipCount = 0;

        while(start != 0 || goal != 0)
        {
            // check if result of both operations are equal
            // if not then flip is required
            if((start & 1) != (goal & 1))
            {
                flipCount++;
            }
        
            // right shift
            start = start >> 1;
            goal = goal >> 1;
        }

        return flipCount;
    }
};