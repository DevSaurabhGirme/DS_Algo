#include <string>
class Solution {
public:
    string customSortString(string order, string str) 
    {
        // We define an array 'count' of size 26 to store the count of occurrences of each character.
        // It is initialized with all elements set to 0.
        // Each index in this array corresponds to a character in the English alphabet. 
        int count[26] = {0};

        // This loop iterates through each character c in the string str. For each character c,
        // it increments the count of that character in the count array.
        // The count is incremented at the index corresponding to the character's position in the alphabet series
    // 1
        for(char &c : str)
        count[c -'a']++; // ASCII values are subtracted to get the according variable

    // traditional loop for 1
        /*
        for(int i = 0; i < str.length(); i++)
        {
            char c = str[i];
            count[c - 'a']++;
        }
        */

        // This loop iterates through each character ch in the order string. For each character ch, 
        // it appends that character to the result string as many times as its count in the 'count' array. 
        // After appending each character, its count in the count array is decremented.
    // 2    
        string result = {};
        for(char &ch : order) 
        {
            while(count[ch-'a'] > 0) 
            {
                count[ch - 'a']--;
                result.push_back(ch);
            }
        }
    // traditional loop for 2
        /*
        string result = {};
        for(int i = 0; i < order.length(); i++)
        {
            char ch = order[i];
            while(ch - 'a' > 0)
            {
                result.push_back(ch);
                count[ch - 'a']--;
            }
        }
        */

    // 3
        //Add the characters which are not present in 'order'
        for(char &c : str) 
        {
            if(count[c-'a'] > 0) 
            {
                result.push_back(c);
            }
        }

    // traditional loop for 3
        /*
        for(int i = 0; i < str.length(); i++)
        {
            char c = str[i];
            if(count[c - 'a'] > 0)
            {
                result.push_back(c);
            }
        }
        */

        return result;
        
    }
};