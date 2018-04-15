#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        /* REJECTED, overflow at line 13 */
        vector<int> v;
        for (int i = 0; i <= rowIndex; i++) {
            int num = 1, den = 1;
            for (int j = 0; j < i; j++) {
                num *= rowIndex - j;
                den *= i - j;
            }
            v.push_back(num / den);
        }
        return v;
     }

     vector<int> getRow(int rowIndex) {
         /* Time: O(n^2), space: O(n) */
         /* Runtime: 3ms */
         vector<int> row(rowIndex + 1, 1);
         for (int i = 1; i <= rowIndex; i++) {
             int prev = 1;
             for (int j = 1; j < i; j++) {
                 int temp = row[j];
                 row[j] += prev;
                 prev = temp;
             }
         }
         return row;
      }
};
