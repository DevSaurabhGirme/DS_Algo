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

        int oddFreq = 0;

        for(char &ch : s)
        {
            // update frequency
            unmap[ch]++;

            if(unmap[ch] % 2 != 0)
            {
                oddFreq++;
            }
            else{
                oddFreq--;
            }
        }

        // adding 1 to length due to an unique letter
        if(oddFreq > 0)
        {
            return n- oddFreq + 1;
        }
        
        return n;
    }
};