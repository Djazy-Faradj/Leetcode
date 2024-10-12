/*
Author: Djazy Faradj
Problem: 13. Roman to Integer
Description: 
 - Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
 - For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
 - Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.
 
 - Given a roman numeral, convert it to an integer.

Note: No notes
Time Complexity: ?
Space Complexity: ?

Relevent Topics: Hash Table, Math, String
*/

class Solution {
public:
    int romanToInt(string s) {
        int outputInt = 0;    // Variable used to store output integer
        const int STRING_SIZE = s.size();   // Length of roman numeral string
        std::unordered_map<char, int> romanTable = {   // Define a hashtable linking each roman letter to a numerical integer
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},

        };

        for (int i = 0; i < STRING_SIZE-1; i++)  // Will loop through the string of the roman number, will stop at second-to-last character
        {
            if (romanTable.at(s[i]) < romanTable.at(s[i+1])) outputInt -= romanTable.at(s[i]);    // If following roman character is larger, substract instead of add
            else outputInt += romanTable.at(s[i]);                                                // Else, just add the number to the current int ouput
        }
        outputInt += romanTable.at(s[STRING_SIZE-1]); // Always add the last roman number to output as it can never be a substraction

        return outputInt;       // Finally return the output
    }
};