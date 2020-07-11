struct Elem
{
    int x, y, val;
    Elem(int x, int y, int val) : x(x), y(y), val(val) {}
};

bool operator<(Elem e1, Elem e2)
{
    return e1.val > e2.val;
}

// T = O(k*log(k)), S = O(k)
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size(), m = matrix[0].size();
        priority_queue<Elem> q;
        for (int i = 0; i < n && i < k; i++)
        {
            q.push(Elem(i, 0, matrix[i][0]));
        }
        for (int i = 0; i < k - 1; i++)
        {
            Elem e = q.top();
            q.pop();
            e.y++;
            if (e.y < m)
            {
                e.val = matrix[e.x][e.y];
                q.push(e);
            }
        }
        return q.top().val;
    }
};