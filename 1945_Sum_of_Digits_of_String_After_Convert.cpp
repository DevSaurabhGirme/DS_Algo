// T.C = O(k*n)     S.C = O(n)

class Solution {
public:
    int getLucky(string s, int k) 
    {
        string s_int;

        // replacing characters with thier coresponding integer value
        for(char &ch : s)
        {
            // a->1, b->2 ... y->25, z->26
            int num = ch - 'a' + 1;
            s_int += to_string(num);
        }

        int sumOfDigits = 0;
        
        // iterate for k times
        while(k > 0)
        {
            sumOfDigits = 0;

            // calculating sum of digits
            for(char &ch : s_int)
            {
                sumOfDigits += ch - '0';
            }

            s_int = to_string(sumOfDigits);
            k--;
        }

        return stoi(s_int);
    }
};