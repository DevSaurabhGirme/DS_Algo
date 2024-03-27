class Solution {
public:
    string reverseWords(string s) 
    {
        // reverse the string
        reverse(s.begin(), s.end());

        int i = 0;
        int n = s.length();
        int l = 0;
        int r = 0;

        while(i < n)
        {
            // until i encounters a space wef completes a word
            while(i < n && s[i] != ' ')
            {
                s[r] = s[i];
                i++;
                r++;
            }

            if(l < r) // check if there's a word to reverse
            {
                reverse(s.begin()+l, s.begin()+r);

                s[r] = ' ';
                r++;

                l = r;
            }
            i++;
        }
        // trim extra spaces atthe end
        s = s.substr(0, r-1);

        return s;

    }
};
