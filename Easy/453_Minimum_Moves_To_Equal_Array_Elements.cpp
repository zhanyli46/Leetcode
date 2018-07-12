#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        // Time: O(n), space: O(1)
        // Runtime: 32ms
        return accumulate(nums.begin(), nums.end(), 0) - *min_element(nums.begin(), nums.end()) * nums.size();
    }
};
