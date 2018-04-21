#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        /* Time: O(n), space: O(1) */
        /* Runtime: 24ms */
        int area = 0, max_area = 0, low = 0, high = height.size() - 1;
        while (low < high) {
            area = min(height[low], height[high]) * (high - low);
            max_area = max(max_area, area);
            if (height[low] < height[high]) low++;
            else high--;
        }
        return max_area;
    }
};
