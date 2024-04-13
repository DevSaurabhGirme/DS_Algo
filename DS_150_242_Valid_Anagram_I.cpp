class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        sort(s.begin(), s.end());

        sort(t.begin(), t.end());

        int result = s.compare(t);
        if(result == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};