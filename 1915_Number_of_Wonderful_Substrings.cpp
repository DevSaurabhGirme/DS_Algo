class Solution {
public:
    typedef long long ll;

    long long wonderfulSubstrings(string word) 
    {
        unordered_map<ll, ll> occurances;

        // count of cumulative XOR (cum_xor) 
        occurances[0] = 1;

        int cum_xor = 0;
        // count of substrings which are wonderful
        ll wonder = 0;

        for(char &ch : word)
        {
            int shift = ch - 'a';
            
            // (1<<shift) => binary representation of ch
            // 'left shift 1' by 'shift' number of times
            cum_xor = cum_xor ^ (1 << shift);

            // increment occurances of cum_xor 
            // this ultimately gives count of occurance of the character in the string
            wonder += occurances[cum_xor];  // for characters having even count

            // for characters having odd count
            // performing XOR of cum_xor with every charater till 'j'
            for(char c = 'a'; c <= 'j'; c++)
            {
                shift = c - 'a';

                ll check_xor = cum_xor ^  (1 << shift);
                // increment count of occurances of check_xor
                wonder += occurances[check_xor];
            }
            occurances[cum_xor]++;
        }

        return wonder;
    }
};