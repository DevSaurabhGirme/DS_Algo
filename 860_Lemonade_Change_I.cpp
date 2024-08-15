class Solution {
public:
    static bool lemonadeChange(vector<int>& bills) 
    {
        int count_5=0, count_10=0;
        
        for(int b: bills)
        {
            switch(b)
            {
                case 5: 
                    count_5++; 
                    break;
            
                case 10: 
                    if (count_5>0) 
                    {
                        count_5--;
                        count_10++;
                    }

                    else
                    {
                        return 0;
                    }

                    break;
            
                case 20:
                    if(count_10>0 && count_5>0) 
                    {
                        count_10--, count_5--;
                    }

                    else if (count_5 > 2) 
                    {
                        count_5 -= 3;
                    }

                    else return 0;
                    
                    break;
            }
        }
        return 1;
    }
};