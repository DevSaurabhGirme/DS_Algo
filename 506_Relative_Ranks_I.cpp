// T.C = O(nlogn)   S.C = O(n)

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        int n = score.size();

        vector<string> result(n);

        unordered_map<int, int> unmap;

        for(int i = 0; i < n; i++)
        {
            unmap[score[i]] = i;
        }

        // descending order
        sort(begin(score), end(score), greater<int>());
    
        for(int i = 0; i < n; i++)
        {
            if(i == 0)
            {
                // 1st rank
                int Ath = unmap[score[i]];
                result[Ath] = "Gold Medal";
            }
            else if(i == 1)
            {
                // 2nd rank
                int Ath = unmap[score[i]];
                result[Ath] = "Silver Medal";
            }
            else if(i == 2)
            {
                // 3rd rank
                int Ath = unmap[score[i]];
                result[Ath] = "Bronze Medal";
            }
            else
            {
                // rest of the ranks
                int Ath = unmap[score[i]];
                result[Ath] = to_string(i+1);
            }
        }
        return result;
    }
};