class Solution {
public:
    vector<int> Compute(string exp)
    {
        vector<int> result;

        for(int i = 0; i < exp.length(); i++)
        {
            if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*')
            {
                // Recusrive call for computing left part of operator
                vector<int> left = Compute(exp.substr(0, i));

                // Recusrive call for computing rest of the part
                vector<int> right = Compute(exp.substr(i+1));
            
                for(int &l : left)
                {
                    for(int &r : right)
                    {
                        if(exp[i] == '+')
                        {
                            result.push_back(l+r);
                        }
                        else if(exp[i] == '-')
                        {
                            result.push_back(l-r);
                        }
                        else
                        {
                            result.push_back(l*r);
                        }
                    }
                }
            }
        }
        if(result.empty())
        {
            result.push_back(stoi(exp));
        }

        return result;
    }

    vector<int> diffWaysToCompute(string exp) 
    {
        return Compute(exp);
    }
};