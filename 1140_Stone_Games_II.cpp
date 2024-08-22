// TLE

class Solution {
public:
    int SolveForAlice(vector<int>& piles, int Person, int Idx, int M, int n)
    {
        if(Idx >= n)
        {
            return 0;
        }

        int result = (Person == 1) ? -1 : INT_MAX;

        long int stones = 0;

        for(int x = 1; x <= min(2*M, n-Idx); x++) // Note: corrected 'n-1' to 'n-Idx'
        {
            stones += piles[Idx + x-1];

            if(Person == 1)
            {
                result = max(result, (int)(stones + SolveForAlice(piles, 0, Idx+x, max(M, x), n)));
            }
            else
            {
                result = min(result, SolveForAlice(piles, 1, Idx+x, max(M, x), n));
            }
        }

        return result;
    }

    int stoneGameII(vector<int>& piles) 
    {
        int n = piles.size();    

        //                  (     , Alice or Bob, index, M, size)
        return SolveForAlice(piles,      1      ,   0  , 1,   n );
    }
};
