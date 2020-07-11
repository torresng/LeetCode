// T = O(n), S = O(1)
class Solution
{
public:
    int calculate(string s)
    {
        int p = 0, n = s.size();
        int sum = 0, part = 0;
        char op = '+';
        while (p < n)
        {
            while (s[p] == ' ')
            {
                p++;
            }
            long num = 0;
            while (p < n && s[p] >= '0' && s[p] <= '9')
            {
                num = num * 10 + s[p] - '0';
                p++;
            }
            if (op == '+')
            {
                sum += part;
                part = num;
            }
            else if (op == '-')
            {
                sum += part;
                part = -num;
            }
            else if (op == '*')
            {
                part *= num;
            }
            else
            {
                part /= num;
            }
            while (s[p] == ' ')
            {
                p++;
            }
            if (p < n)
            {
                op = s[p];
                p++;
            }
        }
        return sum + part;
    }
};