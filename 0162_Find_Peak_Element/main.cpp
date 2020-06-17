// T = O(n), S = O(1)
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        if (nums.empty())
        {
            return -1;
        }
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                return i;
            }
        }
        return n - 1;
    }
};

// T = O(log(n)), S = O(1)
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        if (nums.empty())
        {
            return -1;
        }
        int n = nums.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            int mid = (i + j) >> 1;
            int left = (mid - 1) >= 0 ? nums[mid - 1] : INT_MIN;
            int right = (mid + 1) < n ? nums[mid + 1] : INT_MIN;
            if (left < nums[mid] && right < nums[mid])
            {
                return mid;
            }
            else if (left > nums[mid])
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        return i;
    }
};