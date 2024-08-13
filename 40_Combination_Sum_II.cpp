// T.C = O(2^n)     S.C = O(n)

class Solution {
public:
    void Recur(vector<int>& arr, int t, vector<int> curr_arr, int curr_idx, vector<vector<int>>& combinations)
    {
        if(t < 0)
        {
            return;
        }

        if(t == 0)
        {
            combinations.push_back(curr_arr);
            return;
        }

        for(int i = curr_idx; i < arr.size(); i++)
        {
            // check while tracing back
            if(     i > curr_idx       && arr[i] == arr[i-1])
            {
                continue;
            }

            // take
            curr_arr.push_back(arr[i]);
            // and move forward
            Recur(arr, t-arr[i], curr_arr, i+1, combinations);

            // not take(undo)
            curr_arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) 
    {
        vector<vector<int>> combinations;  
        vector<int> curr_arr;

        sort(arr.begin(), arr.end());

        Recur(arr, target, curr_arr, 0, combinations);

        return combinations;
    }
};