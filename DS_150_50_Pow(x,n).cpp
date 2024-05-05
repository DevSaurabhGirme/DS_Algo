class Solution {
public:

    double solve(double x, long int n)
    {
        if(n == 0)
        {
            return 1;
        }

        if(n < 0)
        {
            // recursive call
            return solve(1/x, -n);
        }

        if(n % 2 == 0)
        {
            // recursive call
            return solve(x*x, n/2);
        }
        else
        {
            // recursive call
            return x*solve(x*x, (n-1)/2);
        }
    }

    double myPow(double x, int n) 
    {
        return solve(x, (long int) n);    
    }
};