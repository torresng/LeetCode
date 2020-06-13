// T = O(n^2), S = O(1)
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int res = 0, minv = INT_MAX;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int k = n - 1; k >= 2; k--)
        {
            int i = 0, j = k - 1;
            while (i < j)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                {
                    return sum;
                }
                if (sum < target)
                {
                    i++;
                }
                else
                {
                    j--;
                }
                int diff = abs(target - sum);
                if (diff < minv)
                {
                    res = sum;
                    minv = diff;
                }
            }
        }
        return res;
    }
};