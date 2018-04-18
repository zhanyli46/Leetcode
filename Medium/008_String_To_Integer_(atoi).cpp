class Solution {
public:
    int myAtoi(string str) {
        /* Time: O(n), space: O(n) */
        /* Runtime: 30ms */
        int i = 0, n = str.length(), num = 0, sign;
        int int_min = -2147483648, int_max = 2147483647;
        string s_num;
        while (i < n) {
            if (str[i] == '+') {
                s_num += '+';
                ++i;
                break;
            } else if (str[i] == '-') {
                s_num += '-';
                ++i;
                break;
            } else if (str[i] >= '0' && str[i] <= '9') {
                s_num += '+';
                break;
            } else if (str[i] == ' ') {
                ++i;
            } else {
                return num;
            }
        }
        while (i < n && str[i] >= '0' && str[i] <= '9') {
            s_num += str[i++];
        }
        if (s_num.empty() || s_num == "+" || s_num == "-") return num;
        if (s_num.length() > 11 && s_num[0] == '+') return int_max;
        if (s_num.length() == 11 && s_num[0] == '+' && s_num > "+2147483647") return int_max;
        if (s_num.length() > 11 && s_num[0] == '-') return int_min;
        if (s_num.length() == 11 && s_num[0] == '-' && s_num > "-2147483648") return int_min;
        sign = (s_num[0] == '+') ? 1 : -1;
        i = 1;
        while (i < s_num.length()) {
            num = num * 10 + (s_num[i++] - '0');
        }
        return sign * num;
    }

    // https://leetcode.com/problems/string-to-integer-atoi/discuss/4654/My-simple-solution
    int myAtoi(string str) {
        /* Elegant solution */
        /* Time: O(n), space: O(n) */
        /* Runtime: 36ms */
        int sign = 1, base = 0, i = 0;
        while (str[i] == ' ') { i++; }
        if (str[i] == '-' || str[i] == '+') {
            sign = 1 - 2 * (str[i++] == '-');
        }
        while (str[i] >= '0' && str[i] <= '9') {
            if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            base  = 10 * base + (str[i++] - '0');
        }
        return base * sign;
    }
};
