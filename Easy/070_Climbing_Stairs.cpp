using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        /* Dynamic programming */
        /* Time: O(n), space: O(1) */
        /* Runtime: 3ms */
        int fst = 0, snd = 1, result = 0;
        for (int i = 0; i < n; i++) {
            result = fst + snd;
            fst = snd;
            snd = result;
        }
        return result;
    }
};
