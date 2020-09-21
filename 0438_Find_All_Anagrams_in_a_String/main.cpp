// T = O(n), S = O(k)
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        if (s.empty() || p.empty())
        {
            return {};
        }
        int sn = s.size(), pn = p.size();
        vector<int> res;
        vector<int> v(26, 0);
        for (auto c : p)
        {
            v[c - 'a']++;
        }
        int i = 0, j = 0;
        while (j < sn)
        {
            if (v[s[j] - 'a'] > 0)
            {
                v[s[j] - 'a']--;
                j++;
            }
            else
            {
                v[s[i] - 'a']++;
                i++;
            }
            if (j - i == pn)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};