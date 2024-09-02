// TLE  T.C = O(k/sum * s)

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) 
    {
        int s = chalk.size();
        
        while(true)
        {
            for(int i = 0; i < s; i++)
            {
                if(k < chalk[i])
                {
                    return i;
                }

                k -= chalk[i];
            }
        }
        return 0;
    }
};