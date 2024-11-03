// T.C = O(n)   S.C = O(n)
// similar to rotate function implementation

class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        if(s.length() != goal.length())
            return false;

        string added = s;

        for(int i = 0; i < s.length(); i++)
        {
            if(added == goal)
                return true;
            
            // retrieve the first character
            char ch = added[0];
            // remove it from the string
            added.erase(0,1);
            // append it to the end of the same string
            added.push_back(ch);
        }

        return false;
    }
};