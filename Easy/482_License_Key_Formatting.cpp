#include <algorithm>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        // Time: O(n), space: O(1)
        // Runtime: 8ms
        string formatted;
        int count = 0;
        reverse(S.begin(), S.end());
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == '-')
                continue;
            if (count == K) {
                formatted += '-';
                count = 0;
            }
            if (S[i] >= 'a' && S[i] <= 'z')
                formatted += S[i] - 'a' + 'A';
            else
                formatted += S[i];
            ++count;
        }
        reverse(formatted.begin(), formatted.end());
        return formatted;
    }
};
