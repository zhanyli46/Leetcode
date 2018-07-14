#include <vector>
#include <cmath>        // abs
#include <algorithm>    // max

using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        // Time: O(nlogn), space: O(1)
        // Runtime: 48ms
        int i = 0, j = 0;
        int radius = 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        while (i < houses.size()) {
            while (j + 1 < heaters.size() && (abs(heaters[j + 1] - houses[i]) <= abs(heaters[j] - houses[i])))
                ++j;
            radius = max(radius, abs(houses[i] - heaters[j]));
            ++i;
        }
        return radius;
    }
};
