// T.C = O(n)

class Solution {
public:
    int winnerIdx(int n, int k)
    {
        if(n == 1)
        {
            return 0;
        }

        int idx = winnerIdx(n-1, k);
        idx = (idx + k) % n;

        return idx;
    }

    int findTheWinner(int n, int k) 
    {
        int winner = winnerIdx(n, k);

        return (winner + 1);
    }
};