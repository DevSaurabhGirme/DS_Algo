class Solution {
public:
    string fractionAddition(string exp) 
    {
        int num = 0;
        int den = 1;

        int i = 0;
        int n = exp.length();

        while(i < n)
        {
            int currNum = 0;
            int currDen = 0;

            bool isNega = (exp[i] == '-');

            if(exp[i] == '+' || exp[i] == '-')
            {
                i++;
            }

            // solving for numerator
            while(i < n && isdigit(exp[i]))
            {
                int val = exp[i] - '0';
                currNum = (currNum*10) + val;
                i++;
            }

            // to skip '/' 
            i++;

            if(isNega == true)
            {
                currNum *= -1;
            }

            // solving for denominator
            while(i < n && isdigit(exp[i]))
            {
                int val = exp[i] - '0';
                currDen = (currDen*10) + val;
                i++;
            }

            // resultant fraction using current numerator,denominator
            // and the one we already had
            num = (num*currDen) + (currNum*den);
            den = den * currDen;
            
        }

        int GCD = abs(__gcd(num, den));

        num /= GCD;
        den /= GCD;

        return to_string(num) + '/' + to_string(den);
    }
};