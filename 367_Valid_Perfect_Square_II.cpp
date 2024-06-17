// T.C = O(sqrt(num))

class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        for(long int i = 1;i <= num; i++)
        {
            if(i*i == num)
            {
                return true;
            }
            if(i*i > num)
            {
                return false;
            }
        }

        return false;
    }
};