// S.C = O(n)   TC = O(n)

class Solution {
public:
    string makeFancyString(string s) 
    {
        // to store fancy string
        string result = "";
    
        result.push_back(s[0]);
    
        int n = s.length();
        
        if(n < 3) 
        {
            return s;
        }
        
        int iCnt = 1;
    
        for(int i = 1; i < n; i++)
        {
            // same character found
            if(s[i] == result.back())
            {
                // increment count
                iCnt++;
                if(iCnt < 3)
                {
                    result.push_back(s[i]);
                }
            }
            else
            {
                iCnt = 1;
                result.push_back(s[i]);
            }
        }
        return result;
    }
};