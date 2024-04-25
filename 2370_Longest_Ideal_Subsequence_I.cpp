// T.C = O(n^2)     S.C = O(n)
// TLE

class Solution {
public:
    int longestIdealString(string s, int k) 
    {   
        int n = s.length();

        // vector to store longest subsequencew ending on j for current i
        vector<int> t(n,1);

        int Ideal_Sub_Len = 1;

        for(int i = 0; i < n; i++)
        {
            for(int j = i-1; j >= 0; j--)
            {
                if(abs(s[i] - s[j]) <= k)
                {
                    t[i] = max(t[i], t[j]+1);
                }
            }
            Ideal_Sub_Len = max(Ideal_Sub_Len, t[i]);
        }
        return Ideal_Sub_Len;
    }
};