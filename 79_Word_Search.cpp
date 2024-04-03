class Solution {
public:

    // four possible directions for moving
    vector<vector<int>> directions{{1,0}, {-1,0}, {0,1}, {0,-1}};

    // global variables
    int m = 0;
    int n = 0;

    // business logic
    bool find(vector<vector<char>>& board, int i , int j, int idx, string& word)
    {
        // reached end of the word
        if(idx == word.length())
        {
            return true;
        }
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$')
        {
            return false;
        }

        if(board[i][j] != word[idx])
        {
            return false;
        }

        /*backtracking*/
        char temp = board[i][j];
        board[i][j] = '$';

        for(auto &dir : directions)
        {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            // recursive call to find with updated i and j
            if(find(board, new_i, new_j, idx+1, word))
            {
                return true;
            }
        }

        board[i][j] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) 
    {
        // colums
        m = board.size();
        // rows
        n = board[0].size();

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == word[0] && find(board, i, j, 0, word))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// i means downwards and j means sideways