// T.C = O(n^2)     S.C = O(n*n)

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) 
    {
        // rows and columns
        int n = matrix[0].size();

        // sum of all elements of the matrix irrespective of sign
        int absSum = 0;
        // count of neagtive elements
        int negaCounts = 0;

        int smallestAbsoluteValue = INT_MAX;

        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < n; j++) 
            {
                absSum += abs(matrix[i][j]);

                negaCounts += matrix[i][j] < 0 ? 1 : 0;

                smallestAbsoluteValue = min(smallestAbsoluteValue, abs(matrix[i][j]));

            }
        }

        if(negaCounts%2 == 0) {
            return absSum;
        }

        return absSum - 2*smallestAbsoluteValue;
    }
};