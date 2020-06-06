// T = O(n), S = O(n)
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.empty())
        {
            return -1;
        }
        int n = nums.size(), res = 0;
        vector<int> d(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (res >= n - 1)
            {
                return d[n - 1];
            }
            if (i > res)
            {
                return -1;
            }
            res = max(res, i + nums[i]);
            int last = min(res, n - 1);
            for (int j = last; j > i && d[j] == 0; j--)
            {
                d[j] = d[i] + 1;
            }
        }
        return -1;
    }
};

// T = O(n), S = O(1)
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.empty())
        {
            return -1;
        }
        if (nums.size() == 1)
        {
            return 0;
        }
        int n = nums.size(), maxVal = 0, jumps = 0, curEnd;
        for (int i = 0; i < n; i++)
        {
            if (maxVal >= n - 1)
            {
                return jumps + 1;
            }
            if (i > maxVal)
            {
                return -1;
            }
            if (i > curEnd)
            {
                jumps++;
                curEnd = maxVal;
            }
            maxVal = max(maxVal, i + nums[i]);
        }
        return -1;
    }
};