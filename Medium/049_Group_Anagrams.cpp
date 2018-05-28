#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /* hashmap + sort */
    /* n: number of elements in strs */
    /* m: average string length in strs */
    /* Time: O(n * mlogm), space: O(n) */
    /* Runtime: 35ms */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram_map;
        vector<vector<string>> anagrams;
        for (int i = 0; i < strs.size(); ++i) {
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            if (anagram_map.find(sorted) == anagram_map.end()) {
                anagram_map[sorted] = {strs[i]};
            } else {
                anagram_map[sorted].push_back(strs[i]);
            }
        }
        for (auto p : anagram_map) {
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};
