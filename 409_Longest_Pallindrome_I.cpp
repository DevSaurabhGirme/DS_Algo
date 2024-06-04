// T.C = O(n)   S.C = O(n)

class Solution {
public:
    int longestPalindrome(string s) 
    {
        int n = s.length();

        if(n == 1)
        {
            return 1;
        }

        unordered_set<char> unset;

        int result = 0;

        for(char &ch : s)
        {
            if(unset.count(ch))
            {
                result += 2;
                unset.erase(ch);
            }
            else
            {
                unset.insert(ch);
            }
        }

        if(!unset.empty())
        {
            // adding anyone unique letter left in the set
            result++;
        }
        
        return result;
    }
};