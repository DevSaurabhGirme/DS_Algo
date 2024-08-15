// T.C = O(n)

class Solution {
public:
    static bool lemonadeChange(vector<int>& bills) 
    {
        int count_5 = 0, count_10 = 0;
        
        for(int bill : bills)
        {
            if(bill == 5)
            {
                count_5++;
            }
            else if(bill == 10)
            {
                if(count_5 > 0)
                {
                    count_5--;
                    count_10++;
                }
                else
                {
                    return false;
                }
            }
            else if(count_10 > 0 && count_5 > 0)
            {
                count_5--;
                count_10--;
            }
            else if(count_5 > 2)
            {
                count_5 = count_5-3;
            }
            else
            {
                return false;
            }
        }
        
        return true;
    }
};