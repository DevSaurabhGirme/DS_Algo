class Solution {
public:
    int appendCharacters(string s, string t) 
    {
        int s_len = s.length();
        int t_len = t.length();    
    
        int i = 0;
        int j = 0;

        while(i < s_len)
        {
            if(s[i] == t[j])
            {
                j++;
            }
            i++;
        }

        int min_char_to_append = 0;

        return min_char_to_append = t_len - j;


    }
};