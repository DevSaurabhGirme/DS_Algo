// T.C = O(n)   S.C = O(t.length())

class Solution {
public:
    string minWindow(string s, string t) 
    {
        int n = s.length();

        if(t.length() > n)
        {
            return "";
        }

        unordered_map<char, int> freq;

        // store the frequency of characters from string t in map
        for(char &ch : t)
        {
            freq[ch]++;
        }

        int requiredCount = t.length();
        int i = 0;
        int j = 0;

        int minWindowSize = INT_MAX;
        // to calculate the window size
        int start_i = 0;

        // iterate through string s
        while (j < n)
        {
            char ch = s[j];
            if(freq[ch] > 0)
            {
                // character found 
                requiredCount--;
            }

            freq[ch]--;

            // shrink the window
            while(requiredCount == 0)
            {
                int currWindowSize = j-i+1;

                if(minWindowSize > currWindowSize)
                {
                    // update the minWindowSize to its minimum
                    minWindowSize = currWindowSize;
                    start_i = i;    // will be used to calculate string of minWindowSize
                }

                // since window is shrinking we increment the count of excluded character
                freq[s[i]]++;

                // unwanted characters wiil have frequency in  negative 
                // therefore they will be omitted by default
                if(freq[s[i]] > 0)
                {
                    requiredCount++;
                }

                i++;    // shrink window
            }
            j++;
        }
        return minWindowSize == INT_MAX ? "" : s.substr(start_i, minWindowSize);
    }
};