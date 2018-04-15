#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /* Brute force: Time Limit Exceeded */
        /* Time: O(n^2), space: O(1) */
        /* Runtime: 10ms */
        int max_profit = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            for (int j = i + 1; j < prices.size(); j++)
                max_profit = max(max_profit, prices[j] - prices[i]);
        }
        return max_profit;
    }

    int maxProfit(vector<int>& prices) {
        /* Time: O(n), space: O(1) */
        /* Runtime: 8ms */
        int n = prices.size(), max_profit = 0, cur_min;
        if (n == 0) return 0;
        cur_min = prices[0];
        for (int i = 0; i < n; i++) {
            cur_min = min(cur_min, prices[i]);
            max_profit = max(max_profit, prices[i] - cur_min);
        }
        return max_profit;
    }
};
