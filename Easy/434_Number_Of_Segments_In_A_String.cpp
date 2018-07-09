using namespace std;

class Solution {
public:
    int countSegments(string s) {
        // Time: O(n), space: O(1)
        // Runtime: 0ms
        int count = 0;
        int i = 0, n = s.length();
        while (i < n) {
            while (i < n && s[i] == ' ') ++i;
            if (i < n) ++count;
            while (i < n && s[i] != ' ') ++i;
        }
        return count;
    }
};
