// T = O(n^3), S = O(1)
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() < 4)
        {
            return {};
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int k = n - 1; k >= 3; k--)
        {
            if (nums[k] * 4 < target)
            {
                break;
            }
            for (int l = k - 1; l >= 2; l--)
            {
                if (nums[l] * 3 + nums[k] < target)
                {
                    break;
                }
                int i = 0, j = l - 1;
                while (i < j)
                {
                    int sum = nums[i] + nums[j] + nums[l] + nums[k];
                    if (sum == target)
                    {
                        res.push_back({nums[i], nums[j], nums[l], nums[k]});
                        while (i < j && nums[i] == nums[i + 1])
                        {
                            i++;
                        }
                        while (i < j && nums[j] == nums[j - 1])
                        {
                            j--;
                        }
                        i++, j--;
                    }
                    else if (sum < target)
                    {
                        ++i;
                    }
                    else
                    {
                        --j;
                    }
                }
                while (l >= 2 && nums[l] == nums[l - 1])
                {
                    l--;
                }
            }
            while (k >= 3 && nums[k] == nums[k - 1])
            {
                k--;
            }
        }
        return res;
    }
};