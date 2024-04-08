class Solution {
 public:
  string addBinary(string a, string b) 
  {
    string sum;
    int carry = 0;
    
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) 
    {
        if (i >= 0)
        {
            carry += a[i--] - '0';
        }
            
        if (j >= 0)
        {
            carry += b[j--] - '0';
        }
        // if 1+1=2 we make sum = 0 for that place and add 1 to the carry
        sum += carry % 2 + '0';
        carry /= 2;
    }

    reverse(begin(sum), end(sum));
    return sum;
  }
};