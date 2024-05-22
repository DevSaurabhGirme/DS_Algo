class Solution {
public:
    int n;

    bool isPalindrome(string &s, int left, int right)
    {
        while(left < right)
        {
            if(s[left++] != s[right--])
            {
                return false;
            }
        }
        return true;
    }

    void backTrack(string s, int idx, vector<string> part, vector<vector<string>>& result)
    {
        if(idx == n){
            result.push_back(part);
            return;
        }

        for(int i = idx; i < n; i++)
        {
            // if current partitioned string is palindrome only them add it to part vector
            if(isPalindrome(s, idx, i))
            {
                part.push_back(s.substr(idx, i-idx+1));
                // call to further expand the partition and repeat the procedure
                backTrack(s, i+1, part, result);

                part.pop_back();
            }
        }
    
    }

    vector<vector<string>> partition(string s) 
    {
        n = s.length();
        // to store final vector of "part" vectors
        vector<vector<string>> result;

        // to store palindrome substring of each partition on "s"
        vector<string> part;

        backTrack(s, 0, part, result);

        return result;
    }
};