#include <vector>
#include <unordered_set>
#include <utility>

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Time: O(26 * word length * word list size), space: O(word list size)
        // Runtime: 1024ms
        unordered_set<string> word_set(wordList.begin(), wordList.end());
        unordered_set<string> front({beginWord}), end({endWord}), temp;
        if (!word_set.count(endWord))
            return 0;
        word_set.erase(endWord);

        int ladder_len = 0;
        while (!front.empty()) {
            ++ladder_len;
            for (string s : front) {
                for (char &c : s) {
                    const char old = c;
                    for (c = 'a'; c < 'z'; ++c) {
                        if (end.count(s)) {
                            return ladder_len + 1;
                        } else if (word_set.count(s)) {
                            word_set.erase(s);
                            temp.insert(s);
                        }
                    }
                    c = old;
                }
            }
            if (temp.size() < end.size())
                swap(temp, end);
            front = move(temp);
            temp.clear();
        }
        return 0;
    }
};
