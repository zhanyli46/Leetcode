#include <vector>

using namespace std;

class NumArray {
public:
    /* Space: O(n) */
    /* Runtime: 32ms */
    NumArray(vector<int> nums) {
        /* Time: O(n) */
        int sum = 0, n = nums.size();
        sums.resize(n);
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            sums[i] = sum;
        }
    }

    int sumRange(int i, int j) {
        /* Time: O(1) */
        if (i == 0) return sums[j];
        else return sums[j] - sums[i - 1];
    }
private:
    vector<int> sums;
};
