// works perfectly

class Solution {
public:
    bool isPalindrome(int str) 
    {   
        // integer to store calculated reversed integer
        long int reversed = 0;
        
        // to store iterated result of %(mod) operator
        int digit = 0;

        // temporary variavle to store input number
        long int temp = str;

        // if number is -ve directly goes to end of the file
        if(str >= 0) //&& str % 10 != 0)
        {
            if(str == 0)
            {
                return true;
            }
            
            // enter the loop until temp is exhausted
            while(temp != 0)
            {
                digit = temp % 10;
                reversed = reversed * 10 + digit;

                temp = temp / 10;
            }
            
            // pallindrome detected
            if(reversed == str)
            {
                return true;
            }
        }
        // not a pallindrome
        return false;
    }
};