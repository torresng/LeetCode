// T = O(log5(n)), S = O(1)
class Solution
{
public:
    int trailingZeroes(int n)
    {
        int res = 0;
        while (n > 0)
        {
            n /= 5;
            res += n;
        }
        return res;
    }
};