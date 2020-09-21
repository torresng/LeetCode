// T = O(k), S = O(1)
class Solution
{
public:
    int reverse(int x)
    {
        long res = 0;
        while (x)
        {
            res = res * 10 + x % 10;
            x /= 10;
            if (res > INT_MAX || res < INT_MIN)
            {
                return 0;
            }
        }
        return res;
    }
};

// T = O(k), S = O(1)
class Solution
{
public:
    int reverse(int x)
    {
        int minv = INT_MIN / 10;
        int maxv = INT_MAX / 10;
        int res = 0;
        while (x)
        {
            if (res < minv || res > maxv)
            {
                return 0;
            }
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};