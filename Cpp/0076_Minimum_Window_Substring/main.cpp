// T = O(n), S = O(m)
class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.empty() || t.empty())
        {
            return "";
        }
        int start = 0, len = INT_MAX, requireCount = t.size();
        int left = 0, right = 0;
        vector<int> h(256, 0);
        for (auto c : t)
        {
            h[c]++;
        }
        for (; right < s.size(); right++)
        {
            char r = s[right];
            if (h[r] > 0)
            {
                requireCount--;
            }
            h[r]--;
            while (requireCount == 0)
            {
                if (right - left + 1 < len)
                {
                    start = left;
                    len = right - left + 1;
                }
                char l = s[left];
                h[l]++;
                if (h[l] > 0)
                {
                    requireCount++;
                }
                left++;
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};