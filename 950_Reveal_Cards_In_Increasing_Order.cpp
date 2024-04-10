class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) 
    {
        int n = deck.size();

        sort(begin(deck), end(deck));

        vector<int> result(n,0);

        bool skip = false;

        int i = 0; // for deck
        int j = 0; // for result

        while(i < n)
        {
            if(result[j] == 0)
            {
                if(skip == false)
                {
                    result[j] = deck[i];
                    i++;
                }

                skip = !skip;
            }
            // iterator in circular manner
            j = (j+1)%n;
        }

        return result;
    }
};