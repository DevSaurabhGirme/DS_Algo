class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        // map to store count of characters in magazine string
        unordered_map<char, int> mMap;

        int rSize = ransomNote.size();
        int mSize = magazine.size();

        for(int i = 0; i < mSize; i++)
        {
            // retrieve character
            char ch = magazine[i];

            // add it to the map
            if(mMap.find(ch) == mMap.end())
            {
                mMap[ch] = 1;
            }
            else
            {
                // if present, increment
                mMap[ch]++;
            }
        }

        // iterate over ransomNote
        for(int i = 0; i < rSize; i++)
        {
            char ch = ransomNote[i];

            //if character present then decrement its count in the map
            if((mMap.find(ch) != mMap.end()) && mMap[ch] > 0)
            {
                mMap[ch]--;
            }
            else
            {
                // not present hence cannot be used for note
                return false;
            }
        }
        return true;
    }
};