// T = O(n), S = O(n)
class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.empty())
        {
            return 0;
        }
        int n = height.size();
        int leftMax = -1, rightMax = -1;
        vector<int> d(n);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            leftMax = max(leftMax, height[i]);
            d[i] = leftMax;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            rightMax = max(rightMax, height[i]);
            d[i] = min(d[i], rightMax);
            res += d[i] - height[i];
        }
        return res;
    }
};

// T = O(n), S = O(1)
class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.empty())
        {
            return 0;
        }
        int res = 0, n = height.size();
        int leftMax = -1, rightMax = -1;
        int i = 0, j = n - 1;
        while (i < j)
        {
            leftMax = max(leftMax, height[i]);
            rightMax = max(rightMax, height[j]);
            if (leftMax < rightMax)
            {
                res += leftMax - height[i];
                i++;
            }
            else
            {
                res += rightMax - height[j];
                j--;
            }
        }
        return res;
    }
};