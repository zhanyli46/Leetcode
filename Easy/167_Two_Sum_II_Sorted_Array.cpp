#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        /* Brute force */
        /* Time: O(n^2), space: O(1) */
        /* Runtime: 144ms */
        int i, j, n = numbers.size();
        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                if (numbers[i] + numbers[j] == target)
                    return {i + 1, j + 1};
                if (numbers[i] + numbers[j] > target)
                    break;
            }
        }
        return vector<int>();
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        /* Two Pointers */
        /* Time: O(n), space: O(1) */
        /* Runtime: 6ms */
        int i = 0, j = numbers.size() - 1;
        while (numbers[i] + numbers[j] != target) {
            if (numbers[i] + numbers[j] < target) i++;
            else j--;
        }
        return {i + 1, j + 1};
    }
};
