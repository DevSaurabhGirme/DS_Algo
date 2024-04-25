// T.C = O(n)     S.C = O(n)

class Solution {
public:
    int longestIdealString(string s, int k) 
    {   
        int n = s.length();

        // vector to store longest subsequence for every alaphabet in string s
        vector<int> t(26,0);

        int Ideal_Sub_Len = 0;

        for(int i = 0; i < n; i++)
        {
            int curr_idx = s[i] - 'a';
            
            // range to look for longest subsequence for i
            int left = max(0, curr_idx - k);
            int right = min(25, curr_idx + k);

            int longest = 0;

            // iterate the range 
            for(int j = left; j <= right; j++)
            {
                longest = max(longest, t[j]);
            }

            // insert longest sequence within the range with current [i]
            t[curr_idx] = max(t[curr_idx], longest+1);

            Ideal_Sub_Len = max(Ideal_Sub_Len, t[curr_idx]);
            
        }
        return Ideal_Sub_Len;
    }
};