class Solution {
public:
    // vector to store
    vector<string> result;

    void Recur(int Idx, string &digits, string &temp, unordered_map<char, string> &keypad)
    {
        // reached end of digits string
        if(Idx >= digits.length())
        {
            result.push_back(temp);
            return;
        }

        char ch = digits[Idx];
        string kstr = keypad[ch];

        for(int i = 0; i < kstr.length(); i++)
        {
            temp.push_back(kstr[i]);
            // recursive call to next digit in digits string
            Recur(Idx + 1, digits, temp, keypad);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) 
    {
        if(digits.length() == 0)
        {
            return {};
        }    
        unordered_map<char, string> keypad;

        keypad['2'] = "abc";
        keypad['3'] = "def";
        keypad['4'] = "ghi";
        keypad['5'] = "jkl";
        keypad['6'] = "mno";
        keypad['7'] = "pqrs";
        keypad['8'] = "tuv";
        keypad['9'] = "wxyz";
  
        string temp = "";

        Recur(0, digits, temp, keypad);
  
        return result;
    }
};