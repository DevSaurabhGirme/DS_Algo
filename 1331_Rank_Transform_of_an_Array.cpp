//T.C : O(n*logn)   S.C : O(n)
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        // to store number and its rank
        unordered_map<int, int> mp;
        // ordered set to keep them in sorted order
        set<int> ord_set(arr.begin(), arr.end());

        int rank = 1;
        // assigning rank
        for(auto &num : ord_set) 
        {
            mp[num] = rank;
            rank++;
        }

        // replacing integer with its rank
        for(int i = 0; i < arr.size(); i++) 
        {
            arr[i] = mp[arr[i]];
        }

        return arr;

    }
};