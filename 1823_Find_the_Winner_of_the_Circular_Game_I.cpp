// T.C = O(n^2)

class Solution {
public:
    int findTheWinner(int n, int k) 
    {
        vector<int> friends;

        for(int i = 1; i <= n; i++)
        {
        friends.push_back(i);
        }

        // referring to 1st friend sitting at index 0
        // game starts here
        int i = 0;

        while(friends.size() >= 1)
        {
            // friend to loose
            int Idx = (i + k - 1) % friends.size();
        
            friends.erase(friends.begin() + Idx);

            i = Idx;
        }

        return friends[0];
    }
};