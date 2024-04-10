class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) 
    {
        int n = deck.size();

        sort(begin(deck), end(deck));

        vector<int> result(n);
        queue<int> q;

        for(int i = 0; i < n; i++)
        {
            q.push(i);
        }

        for(int i = 0; i< n; i++)
        {
            int idx = q.front();
            q.pop();

            result[idx] = deck[i];

            if(!q.empty())
            {
                q.push(q.front());
                q.pop();
            }
        }
        return result;
    }
};