// T.C = O(m*n)     S.C = O(m*n)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        // rows
        int m = matrix.size();
        // columns
        int n = matrix[0].size();            
    
        // denoting current row
        int row = 0;
        // denoting current col
        int col = -1;

        // represnts direction to travel
        //  1 => left to right and top to bottom
        // -1 => right to left and bottom to top
        int direction = 1;
    
        // stores matrix's cell values
        vector<int> elements;

        while(m > 0 && n > 0)
        {
            // row traversal
            for(int i = 0; i < n; i++)
            {
                col += direction;
                elements.push_back(matrix[row][col]);                
            }
            // decrement rows count;
            m--;

            // column traversal
            for(int i = 0; i < m; i++)
            {
                row += direction;
                elements.push_back(matrix[row][col]);
            }
            // decrement columns count;
            n--;

            // change direction
            direction *= -1;
        }

        return elements;
    }
};