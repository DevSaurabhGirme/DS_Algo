class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        // rotating array by n position results in same array again
        // hence it is unnecessary to rotate it more than n times
        // therefore we perform following operation first
        k = k%n;
		
        //             0    ,      7
        reverse(nums.begin(), nums.end());
        
        //             0    ,      0 + 3
        reverse(nums.begin(), nums.begin()+k);

        //             0 + 3  ,      7     
        reverse(nums.begin()+k, nums.end());
		
    }
};