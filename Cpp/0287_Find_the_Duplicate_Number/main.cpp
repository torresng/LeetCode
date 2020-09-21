// T = O(n*log(n)), S = O(1)
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        if (nums.empty())
        {
            return -1;
        }
        int n = nums.size();
        for (auto x : nums)
        {
            if (x < 1 && x > n)
            {
                return -1;
            }
        }
        int l = 1, r = n - 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            int count = 0;
            for (auto x : nums)
            {
                if (x >= l && x <= mid)
                {
                    count++;
                }
            }
            if (count > mid - l + 1)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};

// T = O(n), S = O(1)
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = 0, fast = 0;
        while (true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
            {
                break;
            }
        }
        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};