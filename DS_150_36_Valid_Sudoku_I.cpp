class Solution {
public:

    bool validBox(vector<vector<char>>& board, int sr, int er, int sc, int ec)
    {
        unordered_set<char> unset;

        for(int i = sr; i <= er; i++)
        {
            for(int j = sc; j <= ec; j++)
            {
                if(board[i][j] == '.')
                {
                    continue;
                }
                if(unset.find(board[i][j]) != unset.end())
                {
                    return false;
                }
                unset.insert(board[i][j]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) 
    {
        // validating rows
        for(int row = 0; row < 9; row++)
        {
            unordered_set<char> unset;

            for(int col = 0; col < 9; col++)
            {
                if(board[row][col] == '.')
                {
                    continue;
                }
                if(unset.find(board[row][col]) != unset.end())
                {
                    return false;
                }
                unset.insert(board[row][col]);
            }
        }

        // validating columns
        for(int col = 0; col < 9; col++)
        {
            unordered_set<char> unset;

            for(int row = 0; row < 9; row++)
            {
                if(board[row][col] == '.')
                {
                    continue;
                }
                if(unset.find(board[row][col]) != unset.end())
                {
                    return false;
                }
                unset.insert(board[row][col]);
            }
        }

        // validating 3*3 boxes

        for(int sr = 0; sr < 9; sr+=3)
        {
            int er = sr+2;

            for(int sc = 0; sc < 9; sc+=3)
            {
                int ec = sc+2;

                if(!validBox(board, sr, er, sc, ec))
                {
                    return false;
                }
            }
        }
        return true;
    }
};