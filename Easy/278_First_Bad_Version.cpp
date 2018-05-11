// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        /* Time: O(log n), space: O(1) */
        /* Runtime: 2ms */
        int low = 1;
        int high = n;
        int first;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid)) {
                first = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return first;
    }
};
