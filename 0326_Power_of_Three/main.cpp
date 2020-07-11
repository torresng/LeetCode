// T = O(log3(n)), S = O(1)
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        while (n % 3 == 0)
        {
            n /= 3;
        }
        return n == 1;
    }
};

// T = O(1), S = O(1)
class Solution
{
    const int MAX_POWER = (int)((log(INT_MAX)) / log(3));
    const int MAX_NUM = (int)pow(3, MAX_POWER);

public:
    bool isPowerOfThree(int n)
    {
        return n > 0 && (MAX_NUM % n) == 0;
    }
};

// T = O(1), S = O(1)
class Solution
{
    unordered_set<int> s{1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441,
                         1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467};

public:
    bool isPowerOfThree(int n)
    {
        return s.find(n) != s.end();
    }
};