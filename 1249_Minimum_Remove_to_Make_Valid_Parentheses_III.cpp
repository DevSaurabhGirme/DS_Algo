// best approach

class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        int n = s.length();

        // Iterate from start for extra open brackets
        int open = 0; 

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
            { 
                // increment count of open bracket
                open++;
            }
            else if(s[i] == ')')
            { 
                // if close brackets balanced open brackets
                if(open == 0)
                {  
                    // if no. of close brackets > no. of open brackets
                    // i.e extra closed brackets found after balancing
                    // replace those extras with a special character
                    s[i] = '#';
                }
                else
                {
                    // open > 0 
                    // no. of close brackets < no. of open brackets
                    // if matching parentheses found decrease count of open brackets
                    // hence one pair is now balanced
                    open--;
                }
            }
        }
        
        // Iterate from end for extra closed brackets
        // performing same process for closed brackets now
        int close = 0;

        for(int i = n-1; i >= 0; i--)
        {
            if(s[i] == ')')
            { 
                // for close bracket
                close++;
            }
            else if(s[i] == '(')
            { 
                // for open bracket
                if(close == 0)
                { 
                    // extra open bracets are found are balancing 
                    // hence replace them with the special character
                    // if no. of open brackets > no. of close brackets
                    s[i] = '#';
                }
                else
                {
                    // close > 0
                    // if no. of open brackets < no. of close brackets
                    // if matching parentheses found decrease count of closed brackets
                    // hence pair is now balanced
                    close--;
                }
            }
        }
        
        // Create "ans" by ignoring the special characters '#' 
        // and appending all other charaters
        
        string final_result="";
        for(int i = 0; i < n; i++)
        {
            if(s[i] != '#')
            { 
                final_result.push_back(s[i]);
            }
        }
        return final_result;
    }
};