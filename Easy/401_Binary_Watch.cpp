#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        // Listing and checking
        // Time: O(1), space: O(1)
        // Runtime: 3ms
        vector<string> possible_times;
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 60; ++j) {
                if (bitset<10>((h << 6) | m).count() == num)
                    possible_times.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
            }
        }
        return possible_times;
    }

    vector<string> readBinaryWatch(int num) {
        // Backtracking
        // Time: O(1), space: O(1)
        // Runtime: 3ms
        vector<string> possible_times;
        vector<int> lights = {0};

    }

private:
    int hour_map[4] = {8, 4, 2, 1};
    int minute_map[6] = {32, 16, 8, 4, 2, 1};

    void backtracking(vector<string>& times, vector<int>& lights, int num, int cur_num, int start) {
        if (cur_num == num) {
            add_lights_string(times, lights);
            return;
        }
        
    }

    void add_lights_string(vector<string>& times, vector<int>& lights) {
        int hours = 0, minutes = 0;
        for (int i = 0; i < 4; ++i) {
            hours += lights[i] * hour_map[i];
        }
        for (int i = 0; i < 6; ++i) {
            minutes += lights[i + 4] * minute_map[i];
        }
        if (hours > 12 || minutes > 60) return;
        times.push_back(to_string(hours) + (minutes < 10 ? ":0" : ":") + to_string(minutes));
    }
};
