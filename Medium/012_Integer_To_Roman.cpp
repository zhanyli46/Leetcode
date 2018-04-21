class Solution {
public) {
    string intToRoman(int num) {
        /* Naive approach */
        /* Time: O(n), space: O(1) */
        /* Runtime: 91ms */
        string roman_num;
        while (num > 0) {
            if (num >= 1000) {
                num -= 1000;
                roman_num += "M";
            } else if (num >= 900) {
                num -= 900;
                roman_num += "CM";
            } else if (num >= 500) {
                num -= 500;
                roman_num += "D";
            } else if (num >= 400) {
                num -= 400;
                roman_num += "CD";
            } else if (num >= 100) {
                num -= 100;
                roman_num += "C";
            } else if (num >= 90) {
                num -= 90;
                roman_num += "XC";
            } else if (num >= 50) {
                num -= 50;
                roman_num += "L";
            } else if (num >= 40) {
                num -= 40;
                roman_num += "XL";
            } else if (num >= 10) {
                num -= 10;
                roman_num += "X";
            } else if (num >= 9) {
                num -= 9;
                roman_num += "IX";
            } else if (num >= 5) {
                num -= 5;
                roman_num += "V";
            } else if (num >= 4) {
                num -= 4;
                roman_num += "IV";
            } else {
                num -= 1;
                roman_num += "I";
            }
        }
        return roman_num;
    }

    string intToRoman(int num) {
        /* More Elegant! */
        /* Time: O(n), space: O(1) */
        /* Runtime: 105ms */
        string M[] = {"", "M", "MM", "MMM"};
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num/1000] + C[num % 1000 / 100] + X[num % 100 / 10] + I[num % 10];
    }
};
