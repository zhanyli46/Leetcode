#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        // Time: O(n), space: O(1)
        // Runtime: 0ms
        vector<string> v;
        for (int i = 1; i <= n; ++i) {
            if (i % 5 == 0 && i % 3 == 0)
                v.push_back("FizzBuzz");
            else if (i % 3 == 0)
                v.push_back("Fizz");
            else if (i % 5 == 0)
                v.push_back("Buzz");
            else
                v.push_back(to_string(i));
        }
        return v;
    }
};
