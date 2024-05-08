// T.C = O(nlogn)   S.C = O(n)

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        int n = score.size();

        vector<string> result(n);

        int max_score = *max_element(begin(score), end(score));

        vector<int> arr(max_score+1, -1);

        for(int i = 0; i < n; i++)
        {
            arr[score[i]] = i;
        }

        int rank = 1;

        for(int s = max_score; s >= 0; s--)
        {
            if(arr[s] != -1)
            {
                int Ath = arr[s];

                if(rank == 1)
                {
                    result[Ath] = "Gold Medal";
                }
                else if(rank == 2)
                {
                    result[Ath] = "Silver Medal";
                }
                else if(rank == 3)
                {
                    result[Ath] = "Bronze Medal";
                }
                else
                {
                    result[Ath] = to_string(rank);
                }
                rank++;
            }
        }

        return result;
    }
};