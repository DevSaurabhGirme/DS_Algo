// S.C = O(n)   T.C = O(n)

class Solution {
public:
    int maximumGain(string s, int x, int y) 
    {
        vector<char> ab_v;
        vector<char> ba_v;

        int score = 0;

        // "ab" is valuable x > y
        int flag = 1;

        // deciding which substring is valuable
        if(x < y)
        {
            flag = 0;
        }

        for(char ch : s)
        {
            if(!ab_v.empty())
            {
                // if "ab" is valuable
                if(flag == 1)
                {
                    if(ab_v.back() == 'a' && ch == 'b')
                    {
                        score += x;
                        ab_v.pop_back();
                    }
                    else
                    {
                        ab_v.push_back(ch);
                    }
                }
                else
                {   // if "ba" is valuable
                    if(ab_v.back() == 'b'&& ch == 'a')
                    {
                        score += y;
                        ab_v.pop_back();
                    }
                    else
                    {
                        ab_v.push_back(ch);
                    }
                }
            }
            else
            {
                ab_v.push_back(ch);
            }
        }

        // using the resultant string from ab_v for ba_v
        for(char ch : ab_v)
        {
            // since x was > y means we have successfully calculated score for substring "ab"
            if(!ba_v.empty())
            {
                // we enter the else part to calculate score for substring "ba"
                if(flag == 0)
                {
                    if(ba_v.back() == 'a' && ch == 'b')
                    {
                        score += x;
                        ba_v.pop_back();
                    }
                    else
                    {
                        ba_v.push_back(ch);
                    }
                }
                else
                {
                    if(ba_v.back() == 'b'&& ch == 'a')
                    {
                        score += y;
                        ba_v.pop_back();
                    }
                    else
                    {
                        ba_v.push_back(ch);
                    }
                }
            }
            else
            {
                ba_v.push_back(ch);
            }
        }

        return score;
    }
};