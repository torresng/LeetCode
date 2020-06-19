// T = O(n), S = O(1)
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int p = digits.size() - 1;
        while (p >= 0 && digits[p] == 9)
        {
            digits[p] = 0;
            p--;
        }
        if (p == -1)
        {
            digits.resize(digits.size() + 1, 0);
            digits[0] = 1;
            return digits;
        }
        digits[p] += 1;
        return digits;
    }
};