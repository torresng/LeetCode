// T = O(4^n), S = O(n)
class Solution
{
    vector<string> v{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tvu", "wxyz"};
    vector<string> res;
    void dfs(string digits, int i, string s)
    {
        if (digits.size() == i)
        {
            res.push_back(s);
            return;
        }
        int k = digits[i] - '2';
        for (auto c : v[k])
        {
            dfs(digits, i + 1, s + c);
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
        {
            return {};
        }
        dfs(digits, 0, "");
        return res;
    }
};

// T = O(4^n), S = O(4^n)
class Solution
{
    vector<string> v{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tvu", "wxyz"};

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
        {
            return {};
        }
        queue<string> q;
        q.push("");
        for (auto c : digits)
        {
            string chars = v[c - '2'];
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                string s = q.front();
                q.pop();
                for (auto x : chars)
                {
                    q.push(s + x);
                }
            }
        }
        vector<string> res;
        while (!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};