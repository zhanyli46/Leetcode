#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /* Time: O(n), space: O(1) */
        /* Runtime: 7ms */
        int total_profit = 0;
        for (int i = 1; i < prices.size(); i++)
            total_profit += max(prices[i] - prices[i - 1], 0);
        return total_profit;
    }
};
