#include <vector>
#include <utility> // std::pair
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        // Time: O(n^2), space: O(n)
        // Runtime: 132ms
        unordered_map<int, int> distance_count;
        int num_boomerangs = 0;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = 0; j < points.size(); ++j) {
                if (i == j) continue;
                int x = points[i].first - points[j].first;
                int y = points[i].second - points[j].second;
                int dist = x * x + y * y;
                if (distance_count.find(dist) == distance_count.end()) {
                    distance_count[dist] = 1;
                } else {
                    ++distance_count[dist];
                }
            }
            for (auto p : distance_count)
                num_boomerangs += p.second * (p.second - 1);
            distance_count.clear();
        }
        return num_boomerangs;
    }
};
