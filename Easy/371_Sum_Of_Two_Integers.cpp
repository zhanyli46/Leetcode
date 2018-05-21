class Solution {
public:
    int getSum(int a, int b) {
        /* Time: O(1), space: O(1) */
        /* Runtime: 2ms */
        int carry = 0, sum = 0;
        sum = a ^ b;
        carry = (a & b) << 1;
        while (carry) {
            int temp = sum ^ carry;
            carry = (sum & carry) << 1;
            sum = temp;
        }
        return sum;
    }
};
