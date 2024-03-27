class Solution {
public:
    string decodeAtIndex(string s, int k) 
    {
        int n = s.length();

        // store variable size of result string
        long long size = 0;

        for(int i = 0; i < n; i++)
        {
            // retrieve character
            char ch = s[i];

            // if it is a number
            if(isdigit(ch))
            {
                // subtract 0's ascii value from character ascii value
                // to get its integer value
                size = size *(ch - '0');
            }
            else
            {
                // it is an aplhabet
                size = size + 1;
            }
        }

        // iterate from end of string
        for(int i = n-1; i >= 0; i--)
        {
            // find new k for every iteration for new size
            k = k % size;

            // k==0 means it is the last character in the string
            if(k == 0 && isalpha(s[i]))
            {
                //(size of string , value)
                return string(1 , s[i]);
            }

            // if an alphabet then reduce size by 1
            if(isalpha(s[i]))
            {
                size = size - 1;
            }
            else
            {
                // divide size by size of integer value of characeter number 
                size = size/(s[i] - '0');
            }
        }
        // if nothing found return empty string
        return "";
    }
};