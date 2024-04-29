class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        unordered_set<string> unset;

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                {
                    continue; 
                }

                string row = string(1, board[i][j]) + "_ROW_"+ to_string(i);
                string col = string(1, board[i][j]) + "_COL_"+ to_string(j);
                string box = string(1, board[i][j]) + "_BOX_"+ to_string(i/3) + "_" + to_string(j/3);   
         
                if(unset.find(row) != unset.end() || unset.find(col) != unset.end() || unset.find(box) != unset.end())
                {
                    return false;
                }

                unset.insert(row);
                unset.insert(col);
                unset.insert(box);
            }
        }
        return true;
    }
};