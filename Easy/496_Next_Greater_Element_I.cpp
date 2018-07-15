#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        // m := size of findNums
        // n := size of nums
        // Time: O(m + cn) avg, O(n^2) worst case, space: O(n)
        // Runtime: 4ms
        unordered_map<int, int> M;
        vector<int> v;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int next_greater = -1;
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] > nums[i]) {
                    next_greater = nums[j];
                    break;
                }
            }
            M[nums[i]] = next_greater;
        }
        for (int n : findNums)
            v.push_back(M[n]);
        return v;
    }
};
