// TC = O(col*row*row)      S.C = O(m*n)

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
            for(int i = n-1; i >= 0; i--)
            {
                // empty cell found
                if(mat[i][j] == '.')
                {
                    int stoneRow = -1;

                    // looking for stone
                    for(int k = i-1; k >= 0; k--)
                    {
                        if(mat[k][j] == '*')
                        {
                            break;
                        }
                        else if(mat[k][j] == '#')
                        {
                            stoneRow = k;
                            break;
                        }
                    }

                    if(stoneRow != -1)
                    {
                        mat[i][j] = '#';
                        mat[stoneRow][j] = '.';
                    }
                }
            }
        }
        return mat;
    }
};