// T.C = O(1)     S.C = O(1)

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
    {
        vector<int> answer;

        // array to store prefix xor
        vector<int> prefix_xor(arr.size(), 0);
        // initializing the array
        prefix_xor[0] = arr[0];

        // populating the prefix array with xor'ed values
        for(int i = 1; i < arr.size(); i++)
        {
            prefix_xor[i] = prefix_xor[i-1] ^ arr[i];
        }

        for(vector<int> query : queries)
        {
            // range for obtaining xor values
            int l = query[0];
            int r = query[1];
        
            if(l > 0)
            {
                answer.push_back(prefix_xor[l-1] ^ prefix_xor[r]);
            }
            else
            {
                // left is index 0
                answer.push_back(prefix_xor[r]);
            }
        }

        return answer;
    }
};