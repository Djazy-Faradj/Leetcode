/*
Author: Djazy Faradj
Problem: 58. Length of Last Word
Description: 
 - Given a string s consisting of words and spaces, return the length of the last word in the string.
 - A word is a maximal substring consisting of non-space characters only.

Note: This solution was fairly easy. My approach was to go through the given string backwards and omit any space characters. Once a space character is encountered following a word,
Simply end the loop and break, returning the length value of the word read. This solution beats 100% of submissions in terms of runtime but only 5% in terms of memory. Solutiuon2
will explore ways to make it more optimized memory-wise.

Time Complexity: O(n) # Where n could be the length n of the string if all of it is the word
Space Complexity: O(n) # Where n is the size of the string s which would get stored inside the word string

Relevent Topics: String
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        bool isWord = false;
        string word = "";
        for (int i = s.length()-1; i >= 0; i--)
        {
            if (s[i] == ' ' && isWord == false) continue;
            if (s[i] == ' ' && isWord == true) break;
            else isWord = true;
            word = word + s[i];
        }
        return word.length();
    }
};