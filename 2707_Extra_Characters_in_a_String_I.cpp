// T.C = O(2^n*n*n) TLE

class Solution {
public:
    int Recur(int i, string& s, unordered_set<string>& unset, int n)
    {
        if(i >= n)
        {
            return 0;
        }
        
        // taking current character as extra
        int result = 1 + Recur(i+1, s, unset, n);
    
        for(int j = i; j < n; j++)
        {
            string curr = s.substr(i, j-i+1);
            // if curr present in set
            if(unset.count(curr))
            {
                result = min(result, Recur(j+1, s, unset, n));
            }
        }

        return result;
    }

    int minExtraChar(string s, vector<string>& dictionary) 
    {
        int n = s.length();

        // set for quick access of words
        unordered_set<string> unset(dictionary.begin(), dictionary.end());

        return Recur(0, s, unset, n);
    }
};