// T.C = O(n!*n)    S.C = O(n)  TLE

class Solution {
public:
    int n;
    bool result;

    void Recur(int idx, string& s1, string& s2) 
    {
        // all characters sweeped
        if(idx == n) 
        {
            if (s2.find(s1) != string::npos) 
            {
                result = true;
            }

            return;
        }

        for(int i = idx; i < n; i++) 
        {
            // permutations
            swap(s1[i], s1[idx]);
            
            Recur(idx + 1, s1, s2);

            swap(s1[i], s1[idx]);

            // return if a permutation has been found in s2
            if (result == true) 
                return;
        }
    }

    bool checkInclusion(string s1, string s2) 
    {
        n = s1.length();
        // default result
        result = false;

        Recur(0, s1, s2);

        return result;
    }
};