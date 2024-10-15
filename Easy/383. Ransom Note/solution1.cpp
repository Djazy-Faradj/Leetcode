/*
Author: Djazy Faradj
Problem: 383. Ransom Note
Description: 
 - Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
 - Each letter in magazine can only be used once in ransomNote.

Note: 
Initially, I opted for the solution that appeared obvious to me and seemed the most straight forward, that is, initializing a map containing the alphabet. And by incrementing each letter's
occurence inside the magazine to them decrement them for each instance inside the ransom note and returning false if the value of any element fell below zero. However, to my suprise,
this solution only beats 22% of solutions in terms of runtime and 14% in terms of memory.

Time Complexity: O(m + n) where m is the length of magazine string and n is the length of ransomNote
Space Complexity: O(1) for the unordered_map and O(m+n) for the two strings

Relevent Topics: Hash Table, String, Counting
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> umap = { // Unordered map storing character occurance count in magazine
            {'a', 0},
            {'b', 0},
            {'c', 0},
            {'d', 0},
            {'e', 0},
            {'f', 0},
            {'g', 0},
            {'h', 0},
            {'i', 0},
            {'j', 0},
            {'k', 0},
            {'l', 0},
            {'m', 0},
            {'n', 0},
            {'o', 0},
            {'p', 0},
            {'q', 0},
            {'r', 0},
            {'s', 0},
            {'t', 0},
            {'u', 0},
            {'v', 0},
            {'w', 0},
            {'x', 0},
            {'y', 0},
            {'z', 0}
        }; 
        for (char c : magazine) // Loop through magazine
        {
            umap[c] = umap[c] + 1;
        }
        
        for (char c : ransomNote) // Loop through ransom note to determine if enough characters for ransom note
        {
            umap[c] = umap[c] - 1;
            if (umap[c] < 0) return false; // This condition returns false if note enough characters in magazine
        }
        return true;
    }
};