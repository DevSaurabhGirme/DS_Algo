// T.C = O(n)   S.C = O(1)

class Solution {
public:
    int countSeniors(vector<string>& details) 
    {
        int count = 0;
        for(int i = 0; i < details.size(); i++)
        {
            // converting character age intp integer
            //                  '5'   - '0' *10 +            '8'  - '0'
            //                 =           50   +    8
            int age = (details[i][11] - '0')*10 + (details[i][12] - '0');

            if(age > 60)
            {
                count++;
            }
        }

        return count;
    }
};