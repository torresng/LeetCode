class MedianFinder
{
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    // T = O(log(n)), S = O(n)
    void addNum(int num)
    {
        max_heap.push(num);
        if (max_heap.size() > min_heap.size() + 1)
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        if (!min_heap.empty() && (max_heap.top() > min_heap.top()))
        {
            int minv = min_heap.top(), maxv = max_heap.top();
            min_heap.pop(), max_heap.pop();
            min_heap.push(maxv), max_heap.push(minv);
        }
    }

    // T = O(1)
    double findMedian()
    {
        if ((min_heap.size() + max_heap.size()) % 2 == 1)
        {
            return max_heap.top();
        }
        return (min_heap.top() + max_heap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/**
**Follow up:**

1. If all integer numbers from the stream are between 0 and 100, how would you optimize it?
*/
class MedianFinder
{
    int arr[101] = {0};
    int n = 0;
    int findK(int k)
    {
        int s = 0;
        for (int i = 0; i <= 100; i++)
        {
            s += arr[i];
            if (k <= s)
            {
                return i;
            }
        }
        return -1;
    }

public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    // T = O(1)
    void addNum(int num)
    {
        arr[num]++;
        n++;
    }

    // T = O(1)
    double findMedian()
    {
        if ((n & 1) == 1)
        {
            return findK(n / 2 + 1);
        }
        return (findK(n / 2) + findK(n / 2 + 1)) / 2.0;
    }
};

/**
**Follow up:**

2. If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?
*/
class MedianFinder
{
    class MedianFinderArray
    {
        vector<int> data;

    public:
        void addNum(int num)
        {
            int i = data.size() - 1;
            while (i >= 0 && data[i] > num)
            {
                i--;
            }
            data.insert(data.begin() + i + 1, num);
        }

        int findK(int k)
        {
            return data[k - 1];
        }

        int size()
        {
            return data.size();
        }
    };
    class MedianFinderBetweenZeroAndOneHundred
    {
        int dataCount[101] = {0};
        int n = 0;

    public:
        int findK(int k)
        {
            int cnt = 0;
            for (int i = 0; i <= 100; i++)
            {
                cnt += dataCount[i];
                if (cnt >= k)
                {
                    return i;
                }
            }
            return -1;
        }
        void addNum(int num)
        {
            ++dataCount[num];
            ++n;
        }
        int size()
        {
            return n;
        }
    };

    MedianFinderArray leftData, rightData;
    MedianFinderBetweenZeroAndOneHundred middleData;

public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (num >= 0 && num <= 100)
        {
            middleData.addNum(num);
        }
        else if (num < 0)
        {
            leftData.addNum(num);
        }
        else
        {
            rightData.addNum(num);
        }
    }

    double findMedian()
    {
        int middleSize = middleData.size();
        int leftSize = leftData.size();
        int rightSize = rightData.size();
        int n = middleSize + leftSize + rightSize;
        if ((n & 1) == 1)
        {
            int k = n / 2 + 1;
            if (k > leftSize && k <= leftSize + middleSize)
            {
                return middleData.findK(k - leftSize);
            }
            else if (k <= leftSize)
            {
                return leftData.findK(k);
            }
            else
            {
                return rightData.findK(k - leftSize - middleSize);
            }
        }
        else
        {
            int k = n / 2;
            if (k > leftSize && k + 1 <= leftSize + middleSize)
            {
                k = k - leftSize;
                return (middleData.findK(k) + middleData.findK(k + 1)) / 2.0;
            }
            else if (k + 1 <= leftSize)
            {
                return (leftData.findK(k) + leftData.findK(k + 1)) / 2.0;
            }
            else if (k == leftSize && middleSize > 0)
            {
                return (leftData.findK(k) + middleData.findK(1)) / 2.0;
            }
            else if (k == leftSize && middleSize == 0)
            {
                return (leftData.findK(k) + rightData.findK(1)) / 2.0;
            }
            else if (k == leftSize + middleSize)
            {
                return (middleData.findK(k - leftSize) + rightData.findK(1)) / 2.0;
            }
            else
            {
                k = k - leftSize - middleSize;
                return (rightData.findK(k) + rightData.findK(k + 1)) / 2.0;
            }
        }
    }
};