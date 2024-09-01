class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) 
    {
        int s = original.size();

        if(s != (m*n))
        {
            return {};
        }

        vector<vector<int>> matrix(m, vector<int>(n));

        for (int i = 0; i < s; i++) 
        {
            //      row  column
            matrix[i / n][i % n] = original[i]; // Calculate row and column index
        }

        return matrix;
    }
};