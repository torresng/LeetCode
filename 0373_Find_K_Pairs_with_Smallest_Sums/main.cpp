// T = O(m*n*log(k)), S = O(k)
struct Elem
{
    int x, y, sum;
    Elem(int x, int y, int sum) : x(x), y(y), sum(sum) {}
};
bool operator<(Elem e1, Elem e2)
{
    return e1.sum < e2.sum;
}
class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        if (nums1.empty() || nums2.empty() || k <= 0)
        {
            return {};
        }
        int n = nums1.size(), m = nums2.size();
        priority_queue<Elem> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int sum = nums1[i] + nums2[j];
                if (q.size() < k)
                {
                    q.push(Elem(i, j, sum));
                }
                else if (q.top().sum > sum)
                {
                    q.pop();
                    q.push(Elem(i, j, sum));
                }
            }
        }
        vector<vector<int>> res;
        while (!q.empty())
        {
            Elem e = q.top();
            q.pop();
            res.push_back({nums1[e.x], nums2[e.y]});
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// T = O(k*log(k)), S = O(k)
struct Elem
{
    int x, y, sum;
    Elem(int x, int y, int sum) : x(x), y(y), sum(sum) {}
};
bool operator<(Elem e1, Elem e2)
{
    return e1.sum > e2.sum;
}
class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        if (nums1.empty() || nums2.empty() || k <= 0)
        {
            return {};
        }
        int n = nums1.size(), m = nums2.size();
        priority_queue<Elem> q;
        for (int i = 0; i < n && i < k; i++)
        {
            q.push(Elem(i, 0, nums1[i] + nums2[0]));
        }
        vector<vector<int>> res;
        for (int i = 0; i < k && !q.empty(); i++)
        {
            Elem e = q.top();
            q.pop();
            res.push_back({nums1[e.x], nums2[e.y]});
            e.y++;
            if (e.y < m)
            {
                e.sum = nums1[e.x] + nums2[e.y];
                q.push(e);
            }
        }
        return res;
    }
};