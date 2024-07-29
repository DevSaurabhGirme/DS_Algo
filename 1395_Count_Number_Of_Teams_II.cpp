// Brute Force TLE

class Solution {
public:
    int teams = 0;
    void solve1(vector<int>& rating, vector<int>& ascend, int curr_idx, int prev_idx) 
    {
        if(ascend.size() == 3) 
        {
            teams++;
            return;
        }

        for(int i = curr_idx; i < rating.size(); i++) 
        {
            if (prev_idx == -1 || rating[i] > rating[prev_idx]) 
            {
                ascend.push_back(rating[i]);
                solve1(rating, ascend, i + 1, i);
                ascend.pop_back();
            }
        }
    }

    void solve2(vector<int>& rating, vector<int>& descend, int curr_idx, int prev_idx) 
    {
        if(descend.size() == 3) 
        {
            teams++;
            return;
        }
        for(int i = curr_idx; i < rating.size(); i++) 
        {
            if(prev_idx == -1 || rating[i] < rating[prev_idx]) 
            {
                descend.push_back(rating[i]);
                solve2(rating, descend, i + 1, i);
                descend.pop_back();
            }
        }
    }

    int numTeams(vector<int>& rating) 
    {
        int n = rating.size();
        
        // vector to store strictly ascending team
        vector<int>ascend;
        // vector to store strictly descending team
        vector<int>descend;

        solve1(rating, ascend, 0, -1);
        solve2(rating, descend, 0, -1);
        
        return teams;
    }
};