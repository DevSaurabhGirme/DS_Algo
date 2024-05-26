// T.C = O(3^n)     S.C = O(n)
// TLE

class Solution {
public:
    int Recur(int n, int absence, int consec_late)
    {
        int M = 1e9+7;

        // not eligible for the award
        if(absence > 1 || consec_late > 3)
        {
            return 0;
        }

        if(n == 0)
        {
            // eligible for the award
            return 1;
        }

        int AB = Recur(n-1, absence+1, 0) % M;
        int LA = Recur(n-1, absence, consec_late+1) % M;
        int PR = Recur(n-1, absence, 0) % M;

        // return (AB + LA + PR) % M;
        return ((AB + LA) % M + PR) % M;       

    }

    int checkRecord(int n) 
    {
        return Recur(n, 0, 0);    
    }
};