class Solution {
public:
    void backTrack(int start, int &n, int k, vector<int>& curr_comb, vector<vector<int>>& result)
    {
        if(k == 0)
        {
            result.push_back(curr_comb);
            return;
        }
        if(start > n)
        {
            return;
        }

        curr_comb.push_back(start);  // Take
        backTrack(start+1, n, k-1, curr_comb, result); // Recursive call

        curr_comb.pop_back();        // not take
        backTrack(start+1, n, k, curr_comb, result);

    }

    vector<vector<int>> combine(int n, int k) 
    {   
        // to store combination for current start
        vector<int> curr_comb;

        // 
        vector<vector<int>> result;

        backTrack(1, n, k, curr_comb, result);

        return result;    
    }
};