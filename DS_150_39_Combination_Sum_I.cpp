// T.C = O(2^target * n)    S.c = O(n)

class Solution {
public:
    void backTrack(int Idx, vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& result)
    {
        // reached end
        if(Idx == candidates.size())
        {
            // target satisfied
            if(target == 0)
            {
                result.push_back(temp);
                return;
            }
            return;
        }

        if(candidates[Idx] <= target)
        {
            // take
            temp.push_back(candidates[Idx]);
            // recursive call
            backTrack(Idx, candidates, target-candidates[Idx], temp, result);

            //not take;
            temp.pop_back();
        }
        // recursive call
        backTrack(Idx+1, candidates, target, temp, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        // to store current combinations
        vector<int> temp;
        // to store final result of valid combinations
        vector<vector<int>> result;

        backTrack(0, candidates, target, temp, result);

        return result;
    }
};