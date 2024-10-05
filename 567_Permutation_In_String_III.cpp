class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        int n = s1.length();
        int m = s2.length();

        // If s1 is longer than s2
        // s1 cannot be s2's substring
        if (n > m) 
            return false;

        // vectors to store frequency for s1 and s2
        vector<int> s1_freq(26, 0);
        vector<int> s2_freq(26, 0);

        // populating frequency of characters in s1
        for (int i = 0; i < n; i++) 
        {
            s1_freq[s1[i] - 'a']++;
        }

        int i = 0;
        int j = 0;

        while (j < m) 
        {
            // Include a new character from the right end of the window
            s2_freq[s2[j] - 'a']++;

            // Check if the current window size matches the size of s1
            if (j-i+1 > n) 
            {
                // size exceeded that of s1
                // remove the leftmost character
                // shrink the window
                s2_freq[s2[i] - 'a']--;
                
                i++;
            }

            // Check if the current window's frequency matches s1's frequency
            if (s1_freq == s2_freq) 
            {
                return true;
            }

            j++;
        }

        // No matching window found
        return false;
    }
};