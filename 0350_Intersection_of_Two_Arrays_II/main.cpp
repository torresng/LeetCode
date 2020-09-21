// T = O(n+m), S = O(n)
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.empty() || nums2.empty())
        {
            return {};
        }
        int n = nums1.size(), m = nums2.size();
        unordered_map<int, int> map;
        for (auto x : nums1)
        {
            map[x]++;
        }
        vector<int> res;
        for (auto x : nums2)
        {
            if (map[x] > 0)
            {
                res.push_back(x);
                map[x]--;
            }
        }
        return res;
    }
};

// T = O(n*log(n)+m*log(m)), S = O(1)
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.empty() || nums2.empty())
        {
            return {};
        }
        int n = nums1.size(), m = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (nums1[i] == nums2[j])
            {
                res.push_back(nums1[i]);
                i++, j++;
            }
            else if (nums1[i] < nums2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return res;
    }
};