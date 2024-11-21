// TC = O(n)    S.C = O(1)

class Solution {
public:
    int takeCharacters(string s, int k) 
    {
        int n = s.length();

        int windowKept = 0;

        int i = 0;
        int j = 0;

        int count_a = 0;
        int count_b = 0;
        int count_c = 0;

        for(char& c : s)
        {
            if(c == 'a')
                count_a++;

            else if(c == 'b')
                count_b++;
            else
                count_c++;
        }
        
        // not possible to take k characters
        if(count_a < k || count_b < k || count_c < k)
        {
            return -1;
        }

        // window traversal
        while(j < n)
        {
            // decrementing count as per appearance
            if(s[j] == 'a')
                count_a--;

            else if(s[j] == 'b')
                count_b--;

            else if(s[j] == 'c')
                count_c--;

            // shrinking the window if count goes < k
            while(i <= j && (count_a < k || count_b < k || count_c < k))
            {
                if(s[i] == 'a')
                    count_a++;
                else if(s[i] == 'b')
                    count_b++;
                else
                    count_c++;
                
                i++;
            }

            windowKept = max(windowKept, j-i+1);
            j++;
        }

        // total minutes = length of s(n)
        return n- windowKept;
    }
};