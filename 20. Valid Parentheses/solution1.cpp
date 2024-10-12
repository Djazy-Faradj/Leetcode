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