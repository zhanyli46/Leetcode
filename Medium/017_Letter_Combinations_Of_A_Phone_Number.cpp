#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        /* Time: O(n^3), space: O(1) */
        /* Runtime: 4ms */
        string dict[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int prod = 1, n = digits.length();
        if (n == 0) return vector<string>();
        for (int i = 0; i < n; ++i) {
            prod *= dict[digits[i] - '0'].length();
        }
        vector<string> v(prod, digits);
        for (int i = 0; i < n; ++i) {
            string charset = dict[digits[i] - '0'];
            prod /= charset.length();
            int j = -1, k = 0;
            while (k < v.size()) {
                if (k % prod == 0) j = (j + 1) % charset.length();
                v[k++][i] = charset[j];
            }
        }
        return v;
    }

    vector<string> letterCombinations(string digits) {
        /* Time: O(n^2), space: O(n) */
        /* Runtime: 3ms */
        vector<string> v;
        string dict[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (digits.length() == 0)
            return v;
        v.push_back("");
        return recursiveCombinations(digits, dict, v, 0);
    }

private:
    vector<string> recursiveCombinations(string &digits, string *dict, vector<string> &v, int index) {
        if (index == digits.length()) return;
        int n = v.size();
        vector<string> new_v;
        string charset = dict[digits[index] - '0'];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < charset.length(); ++j) {
                new_v.push_back(v[i] + charset[j]);
            }
        }
        return recursiveCombinations(digits, dict, new_v, index + 1);
    }

};
