/*
Author: Djazy
Problem: 242. Valid Anagram
Description: 
 - Write an algorithm to determine if a number n is happy.
 - A happy number is a number defined by the following process:
 - Starting with any positive integer, replace the number by the sum of the squares of its digits.
 - Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
 - Those numbers for which this process ends in 1 are happy.
 - Return true if n is a happy number, and false if not.

Note: This solution is very good, beating 96.59% in runtime and 37% in memory

Time Complexity: O (n + m) where n is length of s and m is length of t
Space Complexity: O (k) where k is amount of distinct letters in s

Relevent Topics: Hash Table, String, Sorting
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false; // Edge case
        unordered_map<char, int> umap;
        for (char c : s)
        {
            if (umap.find(c) == umap.end()) umap[c] = 1;
            else umap[c]++;
        }
        for (char c : t)
        {
            if (umap.find(c) == umap.end() || --umap[c] == -1) return false;
        }
        return true;
    }
};