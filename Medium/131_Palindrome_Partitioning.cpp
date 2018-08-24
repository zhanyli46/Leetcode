#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        /* Time O(2^n), space O(1) */
        /* Runtime: 8ms */
        vector<string> current;
        vector<vector<string>> partitions;
        partition(s, 0, current, partitions);
        return partitions;
    }
private:
    void partition(const string& s, int index, vector<string>& cur, vector<vector<string>>& parts) {
        if (index == s.length()) {
            parts.push_back(cur);
            return;
        }
        for (int i = index + 1; i <= s.length(); ++i) {
            string sub = s.substr(index, i - index);
            if (isPalindrome(sub)) {
                cur.push_back(sub);
                partition(s, i, cur, parts);
                cur.pop_back();
            }
        }
    }
    bool isPalindrome(string s) {
        int n = s.length(), i = 0, j = n - 1;
        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
};
