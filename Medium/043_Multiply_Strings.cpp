#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        /* Time: O(n), space: O(n) */
        /* Runtime: 11ms */
        if (num1 == "0" || num2 == "0") return "0";
        int l1 = num1.length(), l2 = num2.length();
        vector<int> v(l1 + l2, 0);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < l1; ++i) {
            for (int j = 0; j < l2; ++j)
                v[i + j] += (num1[i] - '0') * (num2[j] - '0');
        }
        for (int i = 0; i < l1 + l2 - 1; ++i) {
            v[i + 1] += v[i] / 10;
            v[i] = v[i] % 10;
        }
        string product(v.size(), '0');
        for (int i = 0; i < v.size(); ++i) {
            product[i] = v[i] + '0';
        }
        while (product.length() != 0 && product[product.length() - 1] == '0')
            product.pop_back();
        reverse(product.begin(), product.end());
        return product;
    }
};
