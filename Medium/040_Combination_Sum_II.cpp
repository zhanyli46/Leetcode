#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<vector<int>> CombSet;
    typedef vector<int> Combination;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        /* Time: O(n^2), space: O(n) */
        /* Runtime: 12ms */
        CombSet set;
        Combination cur;
        sort(candidates.begin(), candidates.end());
        recursiveCombination2(candidates, 0, target, set, cur);
        return set;
    }

    void recursiveCombination2(vector<int>& candidates, int start, int target, CombSet& set, Combination& cur) {
        if (target == 0) set.push_back(cur);
        if (target < 0 || candidates.empty()) return;
        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i - 1] == candidates[i])
                continue;
            if (candidates[i] <= target) {
                cur.push_back(candidates[i]);
                recursiveCombination2(candidates, i + 1, target - candidates[i], set, cur);
                cur.pop_back();
            }
        }
    }
};
