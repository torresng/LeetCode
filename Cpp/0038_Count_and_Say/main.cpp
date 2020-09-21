// T = O(1.3^n), S = O(1.3^n)
class Solution
{
public:
    string countAndSay(int n)
    {
        if (n <= 0)
        {
            return "";
        }
        string res = "1";
        for (int i = 1; i < n; i++)
        {
            int cnt = 1;
            string s;
            for (int p = 0; p < res.size(); p++)
            {
                if (p < res.size() && res[p] == res[p + 1])
                {
                    cnt++;
                }
                else
                {
                    s += to_string(cnt) + res[p];
                    cnt = 1;
                }
            }
            res = s;
        }
        return res;
    }
};