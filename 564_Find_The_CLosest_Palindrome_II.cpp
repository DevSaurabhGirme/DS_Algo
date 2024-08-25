// T.C = O(n)   S.C = O(n)

class Solution {
public:
    long halfToPalindrome(long left, bool even) 
    {
        long resultNum = left;
    
        // given lefthalf is odd hencw remove the last integer
        // as it need not be mirrored
        if (even != true) 
        {
            left = left / 10;
        }

        // generating a palindrome
        while (left > 0) 
        {
            int digit = left % 10;
        
            resultNum = (resultNum * 10) + digit;
            left /= 10;
        }

        return resultNum;
    }

    string nearestPalindromic(string n) 
    {
        int len = n.size();
        int mid = len / 2;
    
        // determining the first half based on length of n
        long firstHalf = stol(n.substr(0, len % 2 == 0 ? mid : mid + 1));

        // vector to store all possible palindromes
        vector<long> possibleResults;

        // Palindrome by mirroring the first half
        possibleResults.push_back(halfToPalindrome(firstHalf, len % 2 == 0));

        // Palindrome by mirroring the first half + 1 
        possibleResults.push_back(halfToPalindrome(firstHalf + 1, len % 2 == 0));
        
        // Palindrome by mirroring the first half -1
        possibleResults.push_back(halfToPalindrome(firstHalf - 1, len % 2 == 0));
        
        // if number is all 9's
        possibleResults.push_back((long)pow(10, len - 1) - 1);
        
        // if number is power of 10
        possibleResults.push_back((long)pow(10, len) + 1);

        // difference between n and possible answer
        long diff = LONG_MAX;
        long Palindrome = 0;

        long n_num = stol(n);

        // checking eac palindrome
        for (long &num : possibleResults) 
        {
            if (num == n_num)
                continue;
        
            // calculating difference
            if (abs(num - n_num) < diff) 
            {
                diff = abs(num - n_num);
                Palindrome = num;
            }
            else if (abs(num - n_num) == diff) 
            {
                Palindrome = min(Palindrome, num);
            }
        }

        return to_string(Palindrome);
    }
};