class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) 
    {
        int curr_min_el = arrays[0][0];
        int curr_max_el = arrays[0].back();

        int max_dist = 0;

        for(int i = 1; i < arrays.size(); i++)
        {
            vector<int> arr = arrays[i];
            int len = arr.size();

            max_dist = max(max_dist, max(arr[len-1] - curr_min_el, curr_max_el - arr[0]));

            curr_min_el = min(curr_min_el, arr[0]);
            curr_max_el = max(curr_max_el, arr[len-1]);

        }

        return max_dist;
    }
};