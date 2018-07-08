#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        /* Time: O(n), space: O(n) */
        /* Runtime: 4ms */
        vector<string> dir;
        int start = 0, end = 1;
        while (end < path.length()) {
            while (end < path.length() && path[end] != '/') ++end;
            string fname = path.substr(start + 1, end - start - 1);
            start = end;
            ++end;
            if (fname == "" || fname == ".") continue;
            else if (fname == ".." && !dir.empty())
                dir.pop_back();
            else if (fname != "..")
                dir.push_back(fname);
        }
        string simple_path;
        for (int i = 0; i < dir.size(); ++i) {
            simple_path += "/" + dir[i];
        }
        return dir.empty() ? "/" : simple_path;
    }
};
