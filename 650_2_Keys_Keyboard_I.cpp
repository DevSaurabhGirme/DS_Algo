// DP

class Solution {
public:
    long int Recur(int currA, int clipA, int n)
    {
        if(currA == n)
        {
            return 0; 
        }

        if(currA > n)
        {
            return INT_MAX;
        }

        long int copyAllAndPaste = 1 + 1 + Recur(currA+currA, currA, n);

        long int paste = 1 + Recur(currA + clipA, clipA, n);

        return min(copyAllAndPaste, paste);
    }

    int minSteps(int n) 
    {
        if(n == 1)
        {
            return 0;
        }

        //              (current_A, clipboard_A, n)
        return 1 + Recur(   1     ,     1      , n );
    }
};