// doesn't work n = palindrome 

class Solution {
public:
    string nearestPalindromic(string n) 
    {
        int len = n.length();
        long long num = stoll(n);

        // if n is a single-digit number
        if(num <= 10) 
        {
            return to_string(num - 1);
        }

        // if n is a power of 10 : 100, 1000
        if(n[0] == '1' && count(n.begin() + 1, n.end(), '0') == len - 1)
        {
            return to_string(num - 1);
        }

        // if n is all 9's 999
        if(count(n.begin(), n.end(), '9') == len) 
        {
            return to_string(num + 2);
        }

        long long diff_left = 0;
        long long diff_right = 0;

        string left_temp = n;
        string right_temp = n;

        if(len % 2 == 0)
        {
            // Handling even length palindromes
            int i = 0;
            int j = len - 1;

            while(i <= j)
            {
                left_temp[j] = n[i];
                i++;
                j--;
            }
            diff_left = abs(stoll(n) - stoll(left_temp));

            i = 0;
            j = len - 1;
            
            while(i <= j)
            {
                right_temp[i] = n[j];
                i++;
                j--;
            }

            diff_right = abs(stoll(n) - stoll(right_temp));

            if(diff_left < diff_right)
            {
                return left_temp;
            }
            else
            {
                return right_temp;
            }
        }
        else
        {
            // Handling odd length palindromes
            int i = 0;
            int j = len - 1;

            while(i <= j)
            {
                left_temp[j] = n[i];
                i++;
                j--;
            }
            diff_left = abs(stoll(n) - stoll(left_temp));

            i = 0;
            j = len - 1;

            while(i <= j)
            {
                right_temp[i] = n[j];
                i++;
                j--;
            }

            diff_right = abs(stoll(n) - stoll(right_temp));

            if(diff_left < diff_right)
            {
                return left_temp;
            }
            else
            {
                return right_temp;
            }
        }

        return "";
    }
};
