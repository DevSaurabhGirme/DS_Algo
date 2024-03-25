// go for 'char' instead of 'string' for the map to avoid
// error: no matching member function for call to 'find' auto it = symbols.find(s[i]);

class Solution {
public:
    int romanToInt(string s) 
    {
        unordered_map<char, int> symbols;

        symbols['I'] = 1;
        symbols['V'] = 5;
        symbols['X'] = 10;
        symbols['L'] = 50;
        symbols['C'] = 100;
        symbols['D'] = 500;
        symbols['M'] = 1000;

        // result integer
        int number = 0;

        int len = s.size();

        // iterate over input string
        for(int i = 0; i < len; i++)
        {
            // variable to hold, find symbol on ith index of string into symbols map
            auto it = symbols.find(s[i]);
    
            // symbol found in the map & whether its corresponding value is less than proceeding symbol's value
            if (it != symbols.end() && it->second < symbols[s[i + 1]]) 
            {
                number = number - symbols[s[i]];
            }
            else
            {
                // found but value is greater than proceeding value
                number = number + symbols[s[i]];
            }
        }

        return number;
    }
};  