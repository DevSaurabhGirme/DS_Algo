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

        unordered_map<char, int> unmap;

        int result = 0;
        bool oddFreq = false;

        // updating frequency
        for(char &ch : s)
        {
            unmap[ch]++;
        }

        for(auto &it : unmap)
        {
            if(it.second % 2 == 0)
            {
                // updating result with letters having even frequency
                result += it.second;
            }
            else
            {
                // for odd frequency reduce one and add the rest pair to 
                // result while flaging current letter as true
                result += it.second-1;
                oddFreq = true;
            }
        }

        if(oddFreq != 0)
        {
            result++;
        }
        
        return result;
    }
};