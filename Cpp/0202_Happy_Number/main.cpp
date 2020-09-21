// T = O(1), S = O(1)
class Solution
{
    int transform(int n)
    {
        int res = 0;
        while (n)
        {
            int a = n % 10;
            res = res + a * a;
            n /= 10;
        }
        return res;
    }

public:
    bool isHappy(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        unordered_set<int> s;
        for (int i = n; i != 1; i = transform(i))
        {
            if (s.find(i) != s.end())
            {
                return false;
            }
            s.insert(i);
        }
        return true;
    }
};

// T = O(1), S = O(1)
class Solution
{
    int transform(int n)
    {
        int res = 0;
        while (n)
        {
            int a = n % 10;
            res += a * a;
            n /= 10;
        }
        return res;
    }

public:
    bool isHappy(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        int slow = n, fast = n;
        while (true)
        {
            slow = transform(slow);
            fast = transform(transform(fast));
            if (fast == 1)
            {
                return true;
            }
            if (slow == fast)
            {
                return false;
            }
        }
    }
};

// T = O(1), S = O(1)
class Solution
{
    int transform(int n)
    {
        int res = 0;
        while (n)
        {
            int a = n % 10;
            res += a * a;
            n /= 10;
        }
        return res;
    }

public:
    bool isHappy(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        vector<bool> happy(101, false);
        happy[1] = true, happy[7] = true, happy[10] = true, happy[13] = true;
        happy[19] = true, happy[23] = true, happy[28] = true, happy[31] = true;
        happy[32] = true, happy[44] = true, happy[49] = true, happy[68] = true;
        happy[70] = true, happy[79] = true, happy[82] = true, happy[86] = true;
        happy[91] = true, happy[94] = true, happy[97] = true, happy[100] = true;

        while (n > 100)
        {
            n = transform(n);
        }
        return happy[n];
    }
};