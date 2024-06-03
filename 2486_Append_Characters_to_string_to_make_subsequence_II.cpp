class Solution {
public:
    int appendCharacters(string s, string t) 
    {
        int s_len = s.length();
        int t_len = t.length();    
    
        int i = 0;
        int j = 0;

        for(;i < s_len;i++)
        {
            if(s[i] == t[j])
            {
                j++;
            }
        }


        return t_len-j;


    }
};