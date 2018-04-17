#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        /* Time:O(n), space: O(n) */
        /* Runtime: 55ms */
        vector<bool> primes(n, true);
        primes[0] = primes[1] = false;
        for (int i = 2; i < n; i++) {
            if (primes[i]) {
                for (int j = i + i; j < n; j += i)
                    primes[j] = false;
            }
        }
        return count(primes.begin(), primes.end(), true);
    }
};
