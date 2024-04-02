class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int idx = digits.size()-1;

        while(idx >= 0)
        {
            if(digits[idx] == 9)
            {
                // case 2: assign 0 instead to that digit
                // then goes to line 27 for further execution
                digits[idx] = 0;
            }
            else
            {
                // case 1: when last digit is < 9
                // simply add and return
                digits[idx] = digits[idx] + 1;
                return digits;
            }

            idx--;
        }
        // case 3: all digits are 9 hence we need a 1 at beginning
        // 999 + 1 = 1000
        digits.insert(digits.begin(), 1); //insert 1 at beginnig of array
        return digits;
    }
};