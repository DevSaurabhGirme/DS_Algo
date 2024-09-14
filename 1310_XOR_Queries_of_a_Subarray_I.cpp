// T.C = O(n+q)     S.C = O(1)

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
    {
        vector<int> answer;

        for(vector<int> query : queries)
        {
            int l = query[0];
            int r = query[1];
        
            int XOR = 0;
            for(int i = l; i <= r; i++)
            {
                XOR = XOR ^ arr[i];
            }

            answer.push_back(XOR);
        }

        return answer;
    }
};