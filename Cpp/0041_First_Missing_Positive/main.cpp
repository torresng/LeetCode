// T = O(n), S = O(1)
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 1;
        }
        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            if (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
            else
            {
                i++;
            }
        }
        for (i = 0; i < n; i++)
        {
            if (i + 1 != nums[i])
            {
                return i + 1;
            }
        }
        return n + 1;
    }
};