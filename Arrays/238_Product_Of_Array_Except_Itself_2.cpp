// executes properly using extra space O(n) instead of O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int Size = nums.size();

        // resultant vector
        vector<int> answer(Size);

        // vector for storing product of elements on LHS of current element
        vector<int> left(Size);

        // vector for storing product of elements on RHS of current element
        vector<int> right(Size);

        // initialization of extreme elements 
        left[0] = 1;
        right[Size - 1] = 1;
    
        // traversing using 2 pointers to calculate products
        for(int i = 1, j = Size - 2; i < Size, j >= 0 ; i++, j--)
        {
            left[i] = left[i - 1] * nums[i - 1];

            right[j] = right[j + 1] * nums[j + 1];
        
        }

        // traversing the resultant array to generate final array
        for(int i = 0; i < Size-1; i++)
        {
            answer[i] = left[i] * right[i];
        }
        return answer;

    }
};