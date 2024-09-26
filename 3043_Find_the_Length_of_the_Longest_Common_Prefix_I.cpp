// T.C = O(m*d)+O(n*d)  S.C = O(total number of prefixes in arr1)

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) 
    {
        unordered_set<int> unset;

        for(int prefix : arr1) 
        {
            // inserting all possible prefixes
            while(unset.count(prefix) == false && prefix > 0) 
            {
                unset.insert(prefix);

                prefix = prefix/10;
            }
        }

        int preLength = 0; 

        for(int num : arr2) 
        {
            while(unset.count(num) == false && num > 0) 
            {
                num /= 10;
            }

            if(num > 0) 
            {
                preLength = max(preLength, static_cast<int>(log10(num) + 1));
            }
        }

        return preLength;    
    }
};