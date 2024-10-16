/*
Author: Djazy Faradj
Problem: 58. Length of Last Word
Description: 
 - Given a string s consisting of words and spaces, return the length of the last word in the string.
 - A word is a maximal substring consisting of non-space characters only.

Note: As expected, solution1 just had a slight mistake. Instead of keeping track of string 'word' in which I store the word being read, I should have just kept count of its 
length by incrementing a integer variable called 'wordLength'. This change saved a large enough amount of memory which allows this solution to beat 100% in runtime and 64%
in memory.

Time Complexity: O(n) # Where n could be the length n of the string if all of it is the word
Space Complexity: O(1) 

Relevent Topics: String
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        bool isWord = false;
        int wordLength = 0;
        for (int i = s.length()-1; i >= 0; i--)
        {
            if (s[i] == ' ' && isWord == false) continue;
            if (s[i] == ' ' && isWord == true) break;
            else isWord = true;
            wordLength++;
        }
        return wordLength;
    }
};