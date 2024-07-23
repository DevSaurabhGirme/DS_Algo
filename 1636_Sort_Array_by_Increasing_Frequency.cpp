class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) 
    {
        unordered_map<int, int> freq;
        
        for (int &num : nums) 
        {
            freq[num]++;
        }

        auto lambda = [&](int &num1, int &num2) 
        {
            // if same frequency return true if num1 is greater than num2 
            if(freq[num1] == freq[num2]) 
            {
                return num1 > num2;
            }

            return freq[num1] < freq[num2];
        };

        sort(begin(nums), end(nums), lambda);

        return nums;
    }
};