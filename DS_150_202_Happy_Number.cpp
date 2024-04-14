// T.C = O(log n * no, of iterations)
// S.C = O(n)

class Solution {
public:
    bool isHappy(int n) 
    {
        if(n == 1 || n == 7)
        {
            return true;
        }

        // set to store sum of squares of digits of n
        set<int> sumOfSquares;

        // sum of squares of digits of n
        int sum = 0;

        int digit = 0;

        // entering infinite loop
        while(1)
        {
            sum = 0;
            while(n != 0)
            {   
                digit = n % 10;

                sum = sum + (digit*digit);

                n = n / 10;
            }

            if(sum == 1)
            {
                // happy number detected
                return true;
            }
            else if (sumOfSquares.find(sum) != sumOfSquares.end())
            {
                // infinte loop detected
                // we found the same 'sum' in the set after k iterations
                return false;
            }

            // if none of above conditions then insert it in the set
            sumOfSquares.insert(sum);

            // reassigning new value to continue the loop
            n = sum;
        }

        return false;
    }
};