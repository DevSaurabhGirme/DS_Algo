// T.C = O(n + nlogn + mlogm)       S.C = O((m+n)*logn)

class Solution {
public:
    int customBS(vector<vector<int>>& items, int qPrice)
    {
        int l = 0;
        int r = items.size()-1;

        int mid;
        int maxB = 0;

        while( l <= r)
        {
            mid = l + (r-l)/2;

            // if mid item's price is > query's price
            // move left
            if(items[mid][0] > qPrice)
            {
                r = mid-1;
            }
            else
            {
                // move right
                maxB = max(maxB, items[mid][1]);
                l = mid+1;
            }
        }
        return maxB;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) 
    {
        int n = items.size();
        int m = queries.size();

        vector<int> answer(m);

        // sorting based on price
        sort(items.begin(), items.end());

        int maxBeautySeen = items[0][1];
        
        // updating the beauty for items
        for(int i = 1; i < n; i++)
        {
            maxBeautySeen = max(maxBeautySeen, items[i][1]);
            items[i][1] = maxBeautySeen;           
        }

        for(int i = 0; i < m; i++)
        {
            int qPrice = queries[i];

            answer[i] = customBS(items, qPrice);
        }

        return answer;
    }
};