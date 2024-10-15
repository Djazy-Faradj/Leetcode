/*
Author: Djazy Faradj
Problem: 383. Ransom Note
Description: 
 - Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
 - Each letter in magazine can only be used once in ransomNote.

Note: 
This solution is the best one I could find and one which I believe to be the optimal solution in c++. It uses the exact same approach, again, but instead uses vectors for faster
results. An advantage of using vectors is that declaring it the way its done below automatically initializes it with 26 indexes of value 0. Hence reproducing my initial idea from solution1.cpp
Indexes are easily accessed by converting the char integer value into a value from 0-26 using: [c - 'a'] and then a final check determines whether to return true or false.
This solution beats 87% of submissions in terms of runtime and 92% in terms of memory.

Time Complexity: O(m + n) where m is the length of magazine string and n is the length of ransomNote
Space Complexity: O(1) as the size of the vector remains constant no matter the input

Relevent Topics: Hash Table, String, Counting
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    vector<int> freq(26);
    for (char& ch : ransomNote)
        freq[ch - 'a']++;
    for (char& ch : magazine)
        freq[ch - 'a']--;
    for (int& val : freq)
        if (val > 0)
            return false;
    return true;
    }
};