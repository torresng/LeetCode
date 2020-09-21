// T = O(log10(n)), S = O(1)
class Solution
{
public:
    int countDigitOne(int n)
    {
        if (n < 1)
        {
            return 0;
        }
        long res = 0, factor = 1;
        while (n / factor != 0)
        {
            int digit = (n / factor) % 10;
            int height = n / (factor * 10);
            if (digit == 0)
            {
                res += height * factor;
            }
            else if (digit == 1)
            {
                res += height * factor;
                res += (n % factor) + 1;
            }
            else
            {
                res += (height + 1) * factor;
            }
            factor *= 10;
        }
        return res;
    }
};