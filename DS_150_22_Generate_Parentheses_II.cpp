// T.C = O(2^2n * 2n)   S.C = O(2n)

class Solution {
public:
    bool isValid(string& str)
    {
        int count = 0;

        for(char &ch : str)
        {
            if(ch == '(')
            {
                count++;
            }
            else{
                count--;
            }

            if(count < 0)
            {
                return false;
            }
        }
        return count == 0;
    }

    void Parenthesis(string& curr_str, int n, vector<string>& answer)
    {
        if(curr_str.length() == 2*n){
            if(isValid(curr_str))
            {
                answer.push_back(curr_str);
            }
            return;
        }

        curr_str.push_back('(');
        Parenthesis(curr_str, n, answer);
        curr_str.pop_back();

        curr_str.push_back(')');
        Parenthesis(curr_str, n, answer);
        curr_str.pop_back();
    }

    vector<string> generateParenthesis(int n) 
    {
        // to store final valid parenthesis
        vector<string> answer;

        string curr_str = "";

        Parenthesis(curr_str, n, answer);

        return answer;
    }

};