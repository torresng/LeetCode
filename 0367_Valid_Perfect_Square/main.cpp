// T = O(log(n)), S = O(1)
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        long i = 1, j = num;
        while (i <= j)
        {
            long mid = (i + j) >> 1;
            long sum = mid * mid;
            if (sum == num)
            {
                return true;
            }
            else if (sum < num)
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        return false;
    }
};

// T = O(log(n)), S = O(1)
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        long x = num;
        while (x * x > num)
        {
            x = (x + num / x) / 2;
        }
        return x * x == num;
    }
};