class Solution {
public:
    int minimumPushes(string word) 
    {
        vector<int> freq(26, 0);

        for(char &ch : word)
        {
            freq[ch- 'a']++;
        }

        // sorted in decreasing order
        sort(begin(freq), end(freq), greater<int>());
    
        int result = 0;

        for(int i = 0; i < 26; i++)
        {
            int count = freq[i];

            int presses = i/8 + 1;

            result = result + (presses * count);
        }

        return result;
    }
};