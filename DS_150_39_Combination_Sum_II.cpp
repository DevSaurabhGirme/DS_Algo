// T.C = O(2^target * n + n)    S.c = O(n)

class Solution {
public:
    int Sum(vector<int> &arr)
    {
        int sum = 0;

        for(int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
        }
        return sum;
    }

    void backTrack(int Idx, vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& result)
    {
        int summation = Sum(temp);

        // caught an invalid sum or reached the end of array
        if(summation > target || Idx >= candidates.size())
        {
            return;
        }

        // found our list
        if(summation == target)
        {
            result.push_back(temp);
            return;
        }
    
        // take
        temp.push_back(candidates[Idx]);
        // recursive call
        backTrack(Idx, candidates, target, temp, result);

        //not take;
        temp.pop_back();
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