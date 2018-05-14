class Solution {
public:
    string reverseVowels(string s) {
        /* Time: O(n), space: O(1) */
        /* Runtime: 12ms */
        string rev_vowel = s;
        int i = 0, j = rev_vowel.length() - 1;
        while (i < j) {
            if (isVowel(rev_vowel[i]) && isVowel(rev_vowel[j])) {
                swap(rev_vowel[i++], rev_vowel[j--]);
            } else if (isVowel(rev_vowel[i])) {
                --j;
            } else if (isVowel(rev_vowel[j])) {
                ++i;
            } else {
                ++i, --j;
            }
        }
        return rev_vowel;
    }
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'A' ||
            c == 'e' || c == 'E' ||
            c == 'i' || c == 'I' ||
            c == 'o' || c == 'O' ||
            c == 'u' || c == 'U';
    }
};
