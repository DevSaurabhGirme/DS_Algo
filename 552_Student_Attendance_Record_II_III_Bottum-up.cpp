// T.C = O(tab[n+1][2][3])
//     ~ O(n)
// S.C = O(n)

// base case n == 0 means 0 days and AB, LA = 0
// execution starts from i = 1(day 1) AB = 0, LA = 0 (original == n)
// ans = 1

class Solution {
public:
    int checkRecord(int n) 
    {
        int M = 1e9 + 7;

        int tab[100001][2][3];

        // base case: days = 0
        for(int AB = 0; AB <= 1; AB++)
        {
            for(int LA = 0; LA <= 2; LA++)
            {
                tab[0][AB][LA] = 1;
            }
        }

        // iterations from day 1 to n
        for(int i = 1; i <= n; i++)
        {
            for(int AB = 0; AB <= 1; AB++)
            {
                for(int LA = 0; LA <= 2; LA++)
                {
                    // Present case
                    long ans = tab[i-1][AB][0] % M;
                
                    // late case
                    ans += (LA+1 <= 2 ? tab[i-1][AB][LA+1] : 0) % M;

                    // absent case
                    ans += (AB+1 <= 1 ? tab[i-1][AB+1][0] : 0) % M;
                
                    tab[i][AB][LA] = ans % M;
                }
            }
        }
    
        return tab[n][0][0];
    }
};