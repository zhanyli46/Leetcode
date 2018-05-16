#include <vector>

using namespace std;

class Solution {
public:
    typedef vector<vector<int>> CombSet;
    typedef vector<int> Combination;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        /* Time: O(n^2), space: O(n) */
        /* Runtime: 23ms */
        CombSet set;
        Combination cur;
        recursiveCombination(candidates, 0, target, set, cur);
        return set;
    }

    void recursiveCombination(vector<int>& candidates, int start, int target, CombSet& set, Combination& cur) {
        if (target == 0) set.push_back(cur);
        if (target < 0 || candidates.empty()) return;
        for (int i = start; i < candidates.size(); ++i) {
            cur.push_back(candidates[i]);
            recursiveCombination(candidates, i, target - candidates[i], set, cur);
            cur.pop_back();
        }
    }
};
