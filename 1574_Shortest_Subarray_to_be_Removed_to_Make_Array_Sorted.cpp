// T.C = O(n)   SC = O(1)

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) 
    {
        int n = arr.size();

        // Find the j'th pointer for non-decreasing sub-array from right side
        int j = n-1;
        
        while(j > 0 && arr[j] >= arr[j-1])
        {
            j--;
        }

        int i = 0;

        // corner case of increasing and valley array
        int result = j;
        
        while(i < j && (i == 0 || arr[i] >= arr[i-1])) 
        {
            // arr[j] < arr[i]
            while(j < n && arr[i] > arr[j]) 
            {
                j++;
            }

            // found jth element such that arr[i] <= arr[j]
            result = min(result, j - i - 1);
            i++;
        }

        return result;

    }
};