// T.C = O(2^2n)   S.C = O(2n)
// optimal

class Solution {
public:
    void Parenthesis(string& curr_str, int n, int open, int close, vector<string>& answer)
    {
        if(curr_str.length() == 2*n){
            answer.push_back(curr_str);
            
            return;
        }

        if(open < n)
        {
            curr_str.push_back('(');
            Parenthesis(curr_str, n, open+1, close, answer);
            curr_str.pop_back();
        }

        if(open > close)
        {
            curr_str.push_back(')');
            Parenthesis(curr_str, n, open, close+1, answer);
            curr_str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) 
    {
        // to store final valid parenthesis
        vector<string> answer;

        string curr_str = "";

        int open = 0;
        int close = 0;

        Parenthesis(curr_str, n, open, close, answer);

        return answer;
    }

};