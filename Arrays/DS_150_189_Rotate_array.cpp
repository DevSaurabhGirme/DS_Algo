// we will define a separate function to reverse the array 
// which gives same result as rotating

class Solution {
public:
    void arrayReverse(vector<int>& nums, int left, int right)
    {
        int size = nums.size();

        int temp = 0;
        while(left < right)
        {
            temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;

            left++;
            right--;
        }    
    }

    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        
        // rotating arra b n position results in same array again
        // hence it is unnecessary to rotate it more than n times
        // therefore we perform following operation first
        k = k % n;

        // calls to our defined function
        // rotate the entire array
        arrayReverse(nums, 0, n-1);

        // rotate first k-1 elements
        arrayReverse(nums, 0, k-1);

        // rotate remaining k elements to get final result
        arrayReverse(nums, k, n-1);

    }
};