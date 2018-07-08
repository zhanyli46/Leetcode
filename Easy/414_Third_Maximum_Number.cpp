#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // LLONG_MIN method
        // Time: O(n), space: O(1)
        // Runtime: 4ms
        long long high, med, low;
        high = med = low = LLONG_MIN;
        for (int n : nums) {
            if (n <= low || n == med || n == high) continue;
            low = n;
            if (low > med) swap(med, low);
            if (med > high) swap(high, med);
        }
        return low == LLONG_MIN ? high : low;
    }

    int thirdMax(vector<int>& nums) {
        // STL Set method
        // Time: O(nlogn), space: O(1)
        // Runtime: 9ms
        set<int> top3;
        for (int n : nums) {
            top3.insert(n);
            if (top3.size() > 3)
                top3.erase(top3.begin());
        }
        return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
    }
};
