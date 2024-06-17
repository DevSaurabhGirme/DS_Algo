// T.C = O(log(num))

class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        if(num == 1)
        {
            return true;
        }

        int l = 2;
        int r = num/2;

        while(l <= r)
        {
            long int mid = (l+r)/2;     // l+(r-l)/2 works same
            long int square = mid*mid;

            if(square == num)
            {
                return true;
            }
            else if(square < num)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }    

        return false;
    }
};