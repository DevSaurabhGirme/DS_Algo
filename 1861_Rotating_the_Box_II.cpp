// TC = O(col*row)      S.C = O(m*n)

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) 
    {
        // rows
        int m = box.size();
        // columns
        int n = box[0].size();    

        // to hold rotated result
        vector<vector<char>> mat(n, vector<char>(m));

        // calculating transpose
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                mat[i][j] = box[j][i];
            }
        }

        // reversing the rows
        for(vector<char> &row : mat)
        {
            reverse(row.begin(), row.end());
        }

        // applying gravity
        for(int j = 0; j < m; j++)
        {
            // empty cell row
            int space = n-1;

            for(int i = n-1; i >= 0; i--)
            {
                // reseting space position
                if(mat[i][j] == '*')
                {
                    space = i-1;
                    continue;
                }

                // making the stone cell empty
                if(mat[i][j] == '#')
                {
                    mat[i][j] = '.';
                    // stone fell
                    mat[space][j] = '#';
                    space--;
                }
            }

        }
        return mat;
    }
};