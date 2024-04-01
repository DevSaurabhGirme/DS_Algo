class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int n = numbers.size();

        int left = 0;
        int right = n-1;

        int sum = 0;

        // array for holding indices of wanted integers
        vector<int> Indices(2,0);

        while(left <= right)
        {
            sum = numbers[left] + numbers[right];

            if(sum == target)
            {
                Indices[0] = left+1;
                Indices[1] = right+1;
                break;
            }

            if(sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return Indices;

    }
};