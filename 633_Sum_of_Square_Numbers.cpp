// T.C = O(sqrt(c))

class Solution {
public:
    bool judgeSquareSum(int c) 
    {
        long int i = 0;
        long int j = round(sqrt(c));
        
        while(i <= j)
        {
            long int squareSum = (i*i) + (j*j);

            if(squareSum == c)
            {
                return true;
            }
            else if(squareSum < c)
            {
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
};