#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Time: O(n^2), space: O(n)
        // Runtime: 0ms
        vector<string> addresses;
        vector<string> cur;
        restore(addresses, cur, s, 0, 4);
        return addresses;
    }
private:
    void restore(vector<string>& addresses, vector<string>& cur, string& s, int start, int n) {
        if (start >= s.length() && n != 0) return;
        if (n == 0) {
            string addr;
            for (auto segment : cur) {
                if (!validSegment(segment))
                    return;
                else
                    addr += "." + segment;
            }
            addresses.push_back(addr.substr(1));
        } else if (n == 1) {
            cur.push_back(s.substr(start));
            restore(addresses, cur, s, s.length(), 0);
            cur.pop_back();
        } else {
            for (int i = 1; i <= 3; ++i) {
                cur.push_back(s.substr(start, i));
                restore(addresses, cur, s, start + i, n - 1);
                cur.pop_back();
            }
        }
    }

    bool validSegment(string& s) {
        int n = s.length();
        if (n == 1)
            return s[0] >= '0' && s[0] <= '9';
        else if (n == 2)
            return s[0] >= '1' && s[0] <= '9' && s[1] >= '0' && s[1] <= '9';
        else if (n == 3)
            return (s[0] == '1' && s[1] >= '0' && s[1] <= '9' && s[2] >= '0' && s[2] <= '9') ||
                   (s[0] == '2' && s[1] >= '0' && s[1] <= '4' && s[2] >= '0' && s[2] <= '9') ||
                   (s[0] == '2' && s[1] == '5' && s[2] >= '0' && s[2] <= '5');
        else return false;
    }
};
