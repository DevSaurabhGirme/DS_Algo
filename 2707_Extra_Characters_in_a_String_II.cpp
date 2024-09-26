// T.C = O(n^3)

class Solution {
public:
    int arr[51];

    int Recur(int i, string& s, unordered_set<string>& unset, int n, unordered_map<int, int>& unmap)
    {
        if(i >= n)
        {
            return 0;
        }

        if(unmap.count(i))
        {
            return unmap[i];
        }

        // taking current character as extra
        int result = 1 + Recur(i+1, s, unset, n, unmap);
    
        for(int j = i; j < n; j++)
        {
            string curr = s.substr(i, j-i+1);
            // if curr present in set
            if(unset.count(curr))
            {
                result = min(result, Recur(j+1, s, unset, n, unmap));
            }
        }

        return unmap[i] = result;
    }

    int minExtraChar(string s, vector<string>& dictionary) 
    {
        int n = s.length();

        // memset(arr, -1, sizeof(arr));

        unordered_map<int, int> unmap;

        // set for quick access of words
        unordered_set<string> unset(dictionary.begin(), dictionary.end());

        return Recur(0, s, unset, n, unmap);
    }
};