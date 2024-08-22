// TLE

class Solution {
public:
    int Recur(int l, int r, string& s, int n)
    {
        // only one character
        if(l == r)
            return 1;
    
        if(l > r)
            return 0;

        int i = l+1;
        while (i <= r && s[i] == s[l])
        {
            i++;
        }
        
        if(i == r+1)
        {
            return 1;
        }

        // print until i-1 and solve for next characters
        int basic = 1+Recur(i, r, s, n);
        
        int lalach = INT_MAX;

        // starting new pointer and looking for same character as the 1st one
        // and iterating until new character is found
        for(int j = i; j <= r; j++)
        {
            if(s[j] == s[l])
            {
                //          ---||---          + Same as 'basic' from above
                int ans = Recur(i, j-1, s, n) + Recur(j, r, s, n);
            
                lalach = min(ans, lalach);
            }
        }

        return min(basi, lalach);
        
    }


    int strangePrinter(string s) 
    {
        int n = s.length();

        return Recur(0, n-1, s, n);    
    }
};