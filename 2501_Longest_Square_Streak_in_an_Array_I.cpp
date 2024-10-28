// T.C = O(nlogn)   S.C= o(n)

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) 
    {
        unordered_map<int, int> unmap;

        // sort the input
        sort(begin(nums), end(nums));

        int maxStreak = 0;

        for(int &num : nums) 
        { 
            // check if this number is a perfect square
            int root = (int)sqrt(num);

            if(root*root == num && unmap.find(root) != unmap.end()) 
            {
                // num found in map. increment the streak
                unmap[num] = 1 + unmap[root];
            } 
            else 
            {
                unmap[num] = 1;
            }

            maxStreak = max(maxStreak, unmap[num]);

        }

        if(maxStreak > 2 ) 
        {
            return maxStreak;
        }

        return -1;
        
    }
};