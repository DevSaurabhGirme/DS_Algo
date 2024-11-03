// T.C = O(n^2)     S.C = O(n)

class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        if(s.length() != goal.length())
            return false;

        for(int iCnt = 0; iCnt < s.length(); iCnt++)
        {
            rotate(s.begin(), s.begin()+1, s.end());

            if(s == goal)
                return true;
        }

        return false;
    }
};