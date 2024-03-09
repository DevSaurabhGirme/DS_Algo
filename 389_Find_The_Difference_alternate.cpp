class Solution {
public:
    char findTheDifference(string s, string t)
    {
        // we create variable s_XOR to store result of XOR operation of each character of string s with 0;
        // we use accumulate function from C++ <numeric> header which performs binary operation in specifies range
                     
                    //function        /range/    /initialization  /function's obj
        char s_XOR = accumulate(s.begin(), s.end(),      0,       bit_xor<>());

        // we create variable t_XOR to store result of XOR operation of each character of string t with 0;
        char t_XOR = accumulate(t.begin(), t.end(), 0, bit_xor<>());
        
        // we finally perform XOR between above results and get our required extra letter 
        res_XOR = s_XOR ^ t_XOR;

        return res_XOR;
    }
};
