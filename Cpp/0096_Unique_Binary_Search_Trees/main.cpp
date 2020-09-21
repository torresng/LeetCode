// T = O(n^2), S = O(n)
class Solution
{
public:
    int numTrees(int n)
    {
        if (n <= 0)
        {
            return 0;
        }
        vector<int> d(n + 1);
        d[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                d[i] += d[j - 1] * d[i - j];
            }
        }
        return d[n];
    }
};

// T = O(n), S = O(1)
class Solution
{
public:
    int numTrees(int n)
    {
        if (n <= 0)
        {
            return 0;
        }
        long res = 1;
        for (int i = 1; i <= n; i++)
        {
            res = res * (n + i) / i;
        }
        return (int)(res / (n + 1));
    }
};