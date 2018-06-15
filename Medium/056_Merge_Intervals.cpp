#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool interval_comp (Interval i1, Interval i2) {
    if (i1.start == i2.start) return i1.end < i2.end;
    return i1.start < i2.start;
}

class Solution {
public:
    /* Time: O(nlogn), space: O(1) */
    /* Runtime: 15ms */
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> merged;
        sort(intervals.begin(), intervals.end(), interval_comp);
        int i = 0;
        while (i < intervals.size()) {
            int start = intervals[i].start, end = intervals[i].end;
            while ((i < intervals.size() - 1) && (end >= intervals[i + 1].start)) {
               ++i;
               end = max(end, intervals[i].end);
            }
            merged.push_back(Interval(start, end));
            ++i;
        }
        return merged;
    }
};
