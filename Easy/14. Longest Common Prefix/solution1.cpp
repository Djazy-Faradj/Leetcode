/*
Author: Djazy Faradj
Problem: 14. Longest Common Prefix
Description: 
 - Write a function to find the longest common prefix string amongst an array of strings.
 - If there is no common prefix, return an empty string "".

Note: No notes
Time Complexity: ?
Space Complexity: ?

Relevent Topics: String, Trie
*/

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