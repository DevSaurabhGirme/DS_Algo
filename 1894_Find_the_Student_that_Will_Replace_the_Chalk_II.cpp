// T.C = O(2n)      S.C = O(n)

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) 
    {
        int n = chalk.size();
        
        // total chalk pices reqired in one iteration
        int chalkSum = 0;

        for(int& chalkPiece : chalk)
        {
            chalkSum += chalkPiece;

            if(chalkSum > k)
            {
                break;
            }
        }

        // chalks remianing after last complete iteration
        int chalkRemain = k % chalkSum;

        for(int i = 0; i < n; i++)
        {
            if(chalkRemain < chalk[i])
            {
                return i;
            }

            chalkRemain -= chalk[i];
        }

        return -1;
    }
};