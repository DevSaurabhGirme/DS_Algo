class Solution {
public:
    string intToRoman(int num) 
    {
        // result
        string roman = "";

        static vector<int> val = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

        static vector<string> symbol = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        // iterate through val
        for(int i = 0; i < 13; i++)
        {
            if(num == 0)
            {
                break;
            }
            // calculate how many times the current value (val[i]) can be subtracted from the input number 'num'
            int times = num/val[i];

            while(times > 0)
            {
                // append the Roman numeral symbol corresponding to the current value
                roman = roman + symbol[i];
                times--;
            }

            num = num % val[i];
        }
        return roman;
          
    }
};