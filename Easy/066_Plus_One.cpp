#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        /* Time: O(n), space: O(1) */
        /* Runtime: 3ms */
        int i = digits.size() - 1, carry = 0;
        digits[i] += 1;
        while (i >= 0) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i--] %= 10;
        }
        if (carry != 0)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};
