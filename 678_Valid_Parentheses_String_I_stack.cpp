class Solution {
public:
    bool checkValidString(string s) 
    {
        // stack to store indices of '('
        stack<int> open; 
        
        // stack to store indices of '*'
        stack<int> star; 

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(') 
            {
                open.push(i); // store index of '('
            } 
            else if (s[i] == '*') 
            {
                star.push(i); // store index of '*'
            }
            else 
            { 
                // s[i] == ')'
                if (!open.empty()) 
                {
                    open.pop(); // match '(' with ')'
                } 
                else if (!star.empty()) 
                {
                    star.pop(); // use '*' to match ')'
                } 
                else 
                {
                    return false; // no valid match found
                }
            }
        }

        // Now, try to match remaining open '(' with '*' if possible
        // when i goes outofbound and we still have open brackets to balance-out
        while (!open.empty() && !star.empty()) 
        {
            // if index of open('(') is < index of star(*)
            // it will look like: ) ( if we replace * with ) which is not balancable
            if (open.top() < star.top()) 
            {
                open.pop();
                star.pop();
            } 
            else 
            {
                break; // stop if no valid match can be found
            }
        }

        // returning true if all '(' are balanced else false after falling out of while loop's condition
        return open.empty(); 
    }
};
