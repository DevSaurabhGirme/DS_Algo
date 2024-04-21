class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n = s.size();

        int l = 0;
        int r = 0;

        int subSize = 0;

        unordered_map<char, int> occurance;

        while(r < n)
        {
            // retrieving the character
            char ch = s[r];

            // character found for first time
            if(occurance.count(ch) == 0)
            {
                // insert it with its index found at
                occurance[ch] = r;

                // update subarray length for current r
                subSize = max(subSize, r-l+1);
            }
            else
            {   // found the character for more than once
                
                //  move the left pointer one step to right of its previous occurnace
                l = max(l, occurance[ch]++);

                // update to latest index of character
                occurance[ch] = r;

                // update the subarray length
                subSize = max(subSize, r-l+1);
            }
            r++;
        }
        return subSize;
    }
};