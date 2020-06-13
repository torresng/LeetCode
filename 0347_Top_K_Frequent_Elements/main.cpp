// T(avg) = O(n), T(worst) = O(n^2), S = O(n)
class Solution
{
    int partition(vector<pair<int, int>> &v, int left, int right)
    {
        if (left >= right)
        {
            return left;
        }
        int x = v[left].second;
        int l = left, r = right;
        while (l < r)
        {
            while (l < r && v[r].second < x)
            {
                r--;
            }
            if (l < r)
            {
                swap(v[l], v[r]);
            }
            while (l < r && v[l].second >= x)
            {
                l++;
            }
            if (l < r)
            {
                swap(v[l], v[r]);
            }
        }
        return l;
    }

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        if (nums.empty())
        {
            return {};
        }
        unordered_map<int, int> map;
        for (auto x : nums)
        {
            map[x]++;
        }
        vector<pair<int, int>> v;
        for (auto m : map)
        {
            v.push_back({m.first, m.second});
        }
        int l = 0, r = v.size() - 1;
        while (l <= r)
        {
            int p = partition(v, l, r);
            if (p == k - 1)
            {
                break;
            }
            else if (p > k - 1)
            {
                r = p - 1;
            }
            else
            {
                l = p + 1;
            }
        }
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(v[i].first);
        }
        return res;
    }
};

// T = O(n), S = O(n)
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        if (nums.empty())
        {
            return {};
        }
        unordered_map<int, int> map;
        for (auto x : nums)
        {
            map[x]++;
        }
        int n = nums.size();
        vector<vector<int>> v(n + 1);
        for (auto m : map)
        {
            v[m.second].push_back(m.first);
        }

        vector<int> res;
        for (int i = v.size() - 1; i >= 0, k > 0; i--)
        {
            for (auto x : v[i])
            {
                res.push_back(x);
                k--;
            }
        }
        return res;
    }
};