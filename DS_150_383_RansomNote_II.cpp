class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        // keeping track of count of charaters in magazine
        int alpha[26] = {0};

        int rSize = ransomNote.size();
        int mSize = magazine.size();

        for(int i = 0; i < mSize; i++)
        {
            // retrieve character
            char ch = magazine[i];
            // increment its frequency by referencing charaters as their corresponding index in alpha array
            alpha[ch - 'a']++;
        }

        // iterate over ransmonNote
        for(int i = 0; i < rSize; i++)
        {
            char ch = ransomNote[i];
            
            // if corresponding character's count is 0 means note cannot be made
            if(alpha[ch - 'a'] == 0)
            {
                return false;
            }
            else
            {
                // decrement count so cannot be used later
                alpha[ch - 'a']--;
            }
        }
        return true;

    }
};