/* Not a good solution, needs to study better approach */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        int prefixLength = 0;
        
        switch(strs.size())
        {
            case 0:
                return "";
            case 1:
                return strs[0];
            default:
                 while (true)
                {
                    if (prefixLength > strs[0].length()) break;
                    prefix = strs[0].substr(0, ++prefixLength);

                    for (string word : strs) 
                    {
                        if ((word.substr(0, prefixLength).find(prefix) != string::npos)) continue;
                        else {
                            prefix.pop_back();
                            return prefix;
                            }
                        }
                }
            return prefix;
        }
    }
};

// strs[0].length() = 0
// prefixLength = 1
// 