// T.C = O(tab[n+1][2][3])
//     ~ O(n)
// S.C = O(n)

// execution starts from day n(given original case) until day 0

class Solution {
public:

    // memoization table
    int tab[100001][2][3];

    int Recur(int n, int absence, int consec_late)
    {
        int M = 1e9+7;

        // not eligible for the award
        if(absence > 1 || consec_late > 2) // >=3
        {
            return 0;
        }

        if(n == 0)
        {
            // eligible for the award
            return 1;
        }

        // string calculated
        if(tab[n][absence][consec_late] != -1)
        {
            return tab[n][absence][consec_late];
        }

        // solving for all states of (n-1)th day
        // absent case
        int AB = Recur(n-1, absence+1, 0) % M;
        // late case
        int LA = Recur(n-1, absence, consec_late+1) % M;
        // present case
        int PR = Recur(n-1, absence, 0) % M;

        // return (AB + LA + PR) % M;
        return tab[n][absence][consec_late] = ((AB + LA) % M + PR) % M;       

    }

    int checkRecord(int n) 
    {
        // initialized each subproblem to -1(unsolved)
        memset(tab, -1, sizeof(tab));

        // first recursive call
        return Recur(n, 0, 0);    
    }
};