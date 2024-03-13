class Solution {
public:
    int pivotInteger(int n) 
    {
        // Calculate sum of all integers
        int rollingSum = (n*(n+1))/2;;

        int Sum = rollingSum;
        int temp = 0;

        for(int i = 1; i <= n ; i++)
        {
            // subtract one element every iteration from sum
            Sum = Sum - i;

            if(temp == Sum)
            {
                // found the pivot
                return i;
            }

            temp = temp + i;
        }
        return -1;
    }
};