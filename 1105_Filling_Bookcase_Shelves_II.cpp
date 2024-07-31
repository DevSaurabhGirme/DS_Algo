// T.C = O(2^n)  S.C = O(n^2)

class Solution {
public:

    int dp[1001][1001];
    int Recur(vector<vector<int>>& books, int i, int width_left, int max_ht, int n, int shelfWidth)
    {
        // processed all the books
        if(i >= n)
        {
            return max_ht;
        }

        if(dp[i][width_left] != -1)
        {
            return dp[i][width_left];
        }

        int curr_book_w = books[i][0];
        int curr_book_h = books[i][1];
    
        int keep = INT_MAX;
        int skip = INT_MAX;

        // keep
        if(curr_book_w <= width_left)
        {
            keep = Recur(books, i+1, width_left - curr_book_w, max(max_ht, curr_book_h), n, shelfWidth);
        }

        // skip (going to next shelf)
        skip = max_ht + Recur(books, i+1, shelfWidth-curr_book_w, curr_book_h, n, shelfWidth);

        return dp[i][width_left] = min(keep, skip);

    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) 
    {
        memset(dp, -1, sizeof(dp));

        int n = books.size();
        
        int width_left = shelfWidth;

        return Recur(books, 0, width_left, 0, n, shelfWidth);
    }
};