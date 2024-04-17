#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    bool isAlphanumeric(char ch) 
    {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
    }

    bool isPalindrome(string s) 
    {
        int n = s.size();
        
        if (n <= 1) 
        {
            return true;
        }

        vector<char> Str;

        // Build the string (only alphanumeric characters)
        for (int i = 0; i < n; i++) 
        {
            char ch = s[i];
            
            if (isAlphanumeric(ch)) {
                Str.push_back(tolower(ch)); // Convert to lowercase and add to vector
            }
        }

        // Check if the filtered string is a palindrome
        int l = 0;
        int r = Str.size() - 1;

        while (l < r) 
        {
            if (filteredStr[l] != filteredStr[r]) 
            {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
};