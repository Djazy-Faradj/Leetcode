/*
Author: Djazy Faradj
Problem: 383. Ransom Note
Description: 
 - Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
 - Each letter in magazine can only be used once in ransomNote.

Note: 
This solution is twice as fast as my first attempt, funny enough, this approach is almost identical to solution1.cpp except the hashmap is not initialized at the beginning and is 
instead only declared and is being added upon as the program loops through the magazine string. This approach is probably faster as it would limit the size of the dictionary to the 
amount of unique characters inside magazine. Therefore, for a magazine content of "aa", dictionary size would only be of 1 instead of the previous 26.

Time Complexity: O(m + n) where m is the length of magazine string and n is the length of ransomNote
Space Complexity: O(t) where t is the amount of unique characters inside the magazine string

Relevent Topics: Hash Table, String, Counting
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> dictionary;

        // Iterate through the magazine and count characters
        for (char c : magazine) {
            if (dictionary.find(c) == dictionary.end()) {
                dictionary[c] = 1;
            } else {
                dictionary[c]++;
            }
        }

        // Iterate through the ransom note and check character counts
        for (char c : ransomNote) {
            if (dictionary.find(c) != dictionary.end() && dictionary[c] > 0) {
                dictionary[c]--;
            } else {
                return false;
            }
        }

        return true;
    }
};