// TC = O(n^3)      S.C = O(n^3)

class Solution {
public:
    int maximumLength(string s) 
    {
        int n = s.length();

        // to store substring and its count
        map<string, int> ord_mp;
    
        for(int i = 0; i < n; i++) 
        {
            // current substring
            string curr;
            for(int j = i; j < n; j++) 
            {
                // substring's last character is same as s's current character 
                if(curr.empty() || curr.back() == s[j]) 
                {
                    curr.push_back(s[j]);
                    // increment count
                    ord_mp[curr]++;
                }
                // different character
                else
                {
                    break;
                }
            }
        }

        int maxLen = 0;

        for(auto &it : ord_mp)
        {
            string str = it.first;
            int count = it.second;
            
            if(count >= 3 && str.length() > maxLen) 
            {
                maxLen = str.length();
            }
        }

        if(maxLen == 0)
        {
            return -1;
        }

        return maxLen;
                
    }
};
