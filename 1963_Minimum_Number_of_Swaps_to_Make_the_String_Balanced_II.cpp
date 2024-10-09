// T.C = O(n)   S.C = O(1)

class Solution {
public:
    int minSwaps(string s) 
    {
        int swaps = 0;

        for(char &ch : s)
        {
            if(ch == '[')
            {
                swaps++;
            }
            else if(swaps > 0)
            {
                swaps--;
            }
        }

        return (swaps+1)/2;
    }
};