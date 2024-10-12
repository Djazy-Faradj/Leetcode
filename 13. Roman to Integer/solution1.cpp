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