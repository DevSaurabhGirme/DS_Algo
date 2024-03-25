// executes properly using space O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int Size = nums.size();

        vector<int> answer(Size);
        answer[0] = 1;

        // we calculate left product and directly insert it into the answer array 
        for(int i = 1; i < Size; i++)
        {
            answer[i] = answer[i - 1] * nums[i - 1];
        }

        // for calculating product of right elements using previous loop's answer array by updating it with final result
        int right = 1;

        // instead of calculating the right elements product as a separate array
        // we will multiply the element to the product of right of the current element in the nums array 
        for(int i = Size-1; i >= 0; i--)
        {
            answer[i] = answer[i] * right;
            right = right * nums[i];
        }

        return answer;

    }
};