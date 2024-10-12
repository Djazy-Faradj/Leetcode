/*
Author: Djazy Faradj
Problem: 20. Valid Parentheses
Description: 
 - Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 - An input string is valid if:
    1. Open brackets must be closed by the same type of brackets.
    2. Open brackets must be closed in the correct order.
    3. Every close bracket has a corresponding open bracket of the same type.

Note: No notes
Time Complexity: ?
Space Complexity: ?

Relevent Topics: String, Stack
*/

class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> bracketMap = {
            {'[', ']'},
            {'{', '}'},
            {'(', ')'}
        };

        int unclosedBracketCount = 0;
        std::vector<char> lastOpenBrackets;

        for (char bracket : s)  // For every character in the provided string, scan the open brackets order and build a vector of required closing bracket
        {

            if (unclosedBracketCount == 0 && (bracket == '}' || bracket == ']' || bracket == ')')) return false;
            if (bracketMap.find(bracket) == bracketMap.end())     // Closing bracket detected
            {
                if (bracket == bracketMap.at(lastOpenBrackets.back()))  // If good closing bracket is used continue through the string and pop the closing bracket required out of vector
                {
                    unclosedBracketCount -= 1;
                    lastOpenBrackets.pop_back();
                    continue;
                }
                else return false; // Wrong closing bracket used so return false 
            }
            unclosedBracketCount += 1;
            lastOpenBrackets.push_back(bracket);
        }
        switch (unclosedBracketCount)
        {
            case 0:
                return true;
            default:
                return false;
        };
    }
};