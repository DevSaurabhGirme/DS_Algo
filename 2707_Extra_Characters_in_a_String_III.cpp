// T.C = O(n^3)

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        int n = s.length();

        unordered_set<string> unset(begin(dictionary), end(dictionary));

        // dp array
        vector<int> arr(n+1, 0);

        for(int i = n-1; i >= 0; i--)
        {
            // taking current character as extra
            arr[i] = 1 + arr[i+1];

            for(int j = i; j < n; j++)
            {
                string curr = s.substr(i, j-i+1);

                // if curr present in set
                if(unset.count(curr))
                {
                    arr[i] = min(arr[i], arr[j+1]);
                }
            }
        }

        return arr[0];
    }
};