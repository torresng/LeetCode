// T = O(n), S = O(1)
class Solution
{
public:
    int titleToNumber(string s)
    {
        long res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            res = res * 26 + s[i] - 'A' + 1;
        }
        return res;
    }
};