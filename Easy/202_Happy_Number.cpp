#include <unordered_set>

using namespace std;

class Solution {
    bool isHappy(int n) {
        /* Store and check */
        /* Time:O(?), space: O(?) */
        /* Runtime: 4ms */
        unordered_set<int> seen_nums;
        while (n != 1) {
            if (seen_nums.count(n))
                return false;
            seen_nums.insert(n);
            int temp = 0;
            while (n != 0) {
                temp += (n % 10) * (n % 10);
                n /= 10;
            }
            n = temp;
        }
        return true;
    }
};
