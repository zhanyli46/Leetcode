using namespace std;

class Solution {
public:
    /* Time: O(n), space: O(1) */
    /* Runtime: 7ms */
    string getPermutation(int n, int k) {
        string perm(n, '0');
        int n_perms = 1;
        int i = 0;
        while (i < n) {
            perm[i] = i++ + '1';
            n_perms *= i;
        }
        for (i = 0, --k; i < n; ++i) {
            n_perms /= n - i;
            int index = i + k / n_perms;
            char c = perm[index];
            while (index > i) {
                perm[index] = perm[index - 1];
                --index;
            }
            perm[i] = c;
            k %= n_perms;
        }
        return perm;
    }
};
