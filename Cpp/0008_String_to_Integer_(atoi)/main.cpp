class Solution {
  public:
    int myAtoi(string str) {
        int start = 0, p = 0, n = str.size();
        int neg = 1;

        while (p < n && str[p] == ' ') {
            p++;
        }
        if (p == n) {
            return 0;
        }

        if (str[p] == '+') {
            p++;
        } else if (str[p] == '-') {
            p++;
            neg = -1;
        }

        while (p < n && str[p] == '0') {
            p++;
        }
        if (p == n) {
            return 0;
        }
        start = p;

        while (p < n && str[p] >= '0' && str[p] <= '9') {
            p++;
        }
        if (p == start) {
            return 0;
        }

        if (p - start > 10) {
            if (neg == 1) {
                return INT_MAX;
            } else {
                return INT_MIN;
            }
        }

        long res = 0;
        for (int i = start; i < p; i++) {
            res = res * 10 + str[i] - '0';
        }
        res *= neg;

        if (res < INT_MIN) {
            return INT_MIN;
        }
        if (res > INT_MAX) {
            return INT_MAX;
        }
        return res;
    }
};
