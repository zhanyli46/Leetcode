#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        // Time: O(n), space: O(1)
        // Runtime: 24ms
        for (int i = sqrt(area); i > 0; --i) {
            if (area % i == 0)
                return {area / i, i};
        }
        return {};
    }
};
