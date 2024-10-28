// T.C = O(n)   SC = O(n)

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) 
    {
        // set for efficient retrieval
        unordered_set<int> unset(begin(nums), end(nums));

        int maxStreak = 0;

        for(int &num : nums) 
        {
            int streak = 0;
            long int curr = num;

            while(unset.find(curr) != unset.end()) 
            {
                streak++;

                // exceeds constraint
                if(curr*curr > 100000) 
                {
                    break;
                }

                curr = curr*curr; //square
            }

            maxStreak = max(maxStreak, streak);
        }

        if(maxStreak >= 2 ) 
        {
            return maxStreak;
        }

        return -1;
    }
};