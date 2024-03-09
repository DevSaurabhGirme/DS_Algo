class Solution 
{
    public:
        int minimumLength(string str)
        {
            int l = 0;
            int r = str.length() - 1;

            while(l < r)
            {
                if(str[l] != str[r])
                {
                    break;
                    return 0;
                }

                while(l <= r && str[l] == str[l+1])
                {
                    l++;
                }
                while(l <= r && str[r] == str[r-1])
                {
                    r--;
                }
            }

            return r - l + 1;
        }

};