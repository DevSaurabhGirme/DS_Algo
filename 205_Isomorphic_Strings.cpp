class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        unordered_map<char, char>unmap1;
        unordered_map<char, char>unmap2;

        int m =s.length();

        for(int i = 0;i < m; i++)
        {
            char ch1 = s[i];
            char ch2 = t[i];

            // ch1 PRESENT BUT NOT EQUAL TO ch2 and vice versa
            if(unmap1.find(ch1) != unmap1.end() && unmap1[ch1] != ch2 || unmap2.find(ch2) != unmap2.end() && unmap2[ch2] != ch1)
            {
                return false;
            }

            unmap1[ch1] = ch2;
            unmap2[ch2] = ch1;
        }

        return true;
    }
};