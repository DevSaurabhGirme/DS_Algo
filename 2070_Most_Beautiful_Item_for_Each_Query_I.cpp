// Didn't work

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) 
    {
        //         p,b    p,b    p,b    p,b    p,b
        // items [[1,2], [3,2], [2,4], [5,6], [3,5]], queries = [1,2,3,4,5,6]
        int n = items.size();

        vector<int> answer(n);            

        for(int &query : queries)
        {
            int maxBeauty = -1;

            for(auto &item : items)
            {
                if(query <= item[0])
                {
                    maxBeauty = item[1];
                }
            }

            answer.push_back(maxBeauty);
        }
        
        return answer;
    }
};