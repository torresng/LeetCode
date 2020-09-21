// T = O(c ^ 1/2), S = O(1)
class Solution
{
    bool isSquare(int c)
    {
        int x = sqrt(c);
        return x * x == c;
    }

public:
    bool judgeSquareSum(int c)
    {
        int x = sqrt(c);
        for (int i = 0; i <= x; i++)
        {
            if (isSquare(c - i * i))
            {
                return true;
            }
        }
        return false;
    }
};

// T = O(c ^ 1/2), S = O(c ^ 1/2)
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        unordered_set<int> s;
        int x = sqrt(c);
        for (int i = 0; i <= x; i++)
        {
            s.insert(i * i);
            if (s.find(c - i * i) != s.end())
            {
                return true;
            }
        }
        return false;
    }
};

// T = O(c ^ 1/2), S = O(1)
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        long i = 0, j = sqrt(c);
        while (i <= j)
        {
            long sum = i * i + j * j;
            if (sum == c)
            {
                return true;
            }
            else if (sum < c)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return false;
    }
};

// T = O(c ^ 1/2), S = O(1)
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        for (int i = 2; i * i <= c; i++)
        {
            int cnt = 0;
            while (c % i == 0)
            {
                ++cnt;
                c /= i;
            }
            if (i % 4 == 3 && (cnt & 1) == 1)
            {
                return false;
            }
        }
        return c % 4 != 3;
    }
};