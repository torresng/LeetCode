// T = O(n^2), S = O(1)
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        for (int i = 0; i < n; i++)
        {
            int tank = 0;
            for (int j = i; j < i + n; j++)
            {
                int k = j % n;
                tank += gas[k] - cost[k];
                if (tank < 0)
                {
                    break;
                }
            }
            if (tank >= 0)
            {
                return i;
            }
        }
        return -1;
    }
};

// T = O(n), S = O(1)
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size(), j = 0;
        for (int i = 0; i < n; i = j + 1)
        {
            int tank = 0;
            for (j = i; j < i + n; j++)
            {
                int k = j % n;
                tank += gas[k] - cost[k];
                if (tank < 0)
                {
                    break;
                }
            }
            if (tank >= 0)
            {
                return i;
            }
        }
        return -1;
    }
};

// T = O(n), S = O(1)
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int total = 0, task = 0, start = 0;
        for (int i = 0; i < n; i++)
        {
            total += gas[i] - cost[i];
            task += gas[i] - cost[i];
            if (task < 0)
            {
                task = 0;
                start = i + 1;
            }
        }
        return total < 0 ? -1 : start;
    }
};