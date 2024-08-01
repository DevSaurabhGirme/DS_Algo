// T.C = O(n)   S.C = O(1)

class Solution {
public:
    int countSeniors(vector<string>& details) 
    {
        int count = 0;
        for(string detail : details)
        {
            string age = detail.substr(11,2);

            if(age > "60")
            {
                count++;
            }
        }
        return count;
    }
};