// T.C = O(|allowed| + |word in words|)     SC = O(1)

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) 
    {
        int arr[26] = {0};    

        // marking as present
        for(char& ch : allowed)
        {
            arr[ch - 'a'] = 1;
        }

        int Cnt = 0;

        for(string &word : words)
        {
            int flag = 1;

            for(char &ch : word)
            {
                // consistency not found
                if(arr[ch - 'a'] == 0)
                {
                    flag = 0;
                    break;
                }
            }

            Cnt = Cnt + flag;
        }

        return Cnt;
    }
};