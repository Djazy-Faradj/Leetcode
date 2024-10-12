/*
Author: Djazy Faradj
Problem: 2423. Remove Letter To Equalize Frequency
Description: 
 - You are given a 0-indexed string word, consisting of lowercase English letters. You need to select one index and remove the letter at that index from word so that the frequency of every letter present in word is equal.
 - Return true if it is possible to remove one letter so that the frequency of all letters in word are equal, and false otherwise.
 - The frequency of a letter x is the number of times it occurs in the string.
 - You must remove exactly one letter and cannot choose to do nothing.
 

Note: No notes
Time Complexity: ?
Space Complexity: ?

Relevent Topics: Hash Table, String, Counting
*/

class Solution {
public:
    // Loop through the string
    // Log each character inside an unordered map
    // Then, check which letter frequency differs from the rest
    // Determine whether to add or remove
    // Return false if can't fix
    // Else return true

    bool equalFrequency(string word) {
        unordered_map<char, int> umap = {};
        int umap_value;
        for (char c : word)
        {
            if (umap.find(c) == umap.end())
            {
                umap[c] = 1; //If character is not in the unordered map, first encounter, therefore add it and set it to 1
            }
            else
            {
                umap[c] = umap[c]+1;
                umap_value = umap[c];
            }
        }

        // iterating over all value of umap 
        unordered_map<char, int>::iterator itr; 
        int variationCount = 0;
        int lowestValue = 100;
        int highestValue = 0;
        int highestValueCount = 0;
        int lowestValueCount = 0;
        for (itr = umap.begin(); itr != umap.end(); itr++)  
        { 
            // itr works as a pointer to  
            // pair<char, int> type  
            // itr->first stores the key part and 
            // itr->second stores the value part 

            // Count how many different variations in freq.
            if (itr->second != highestValue && itr->second != lowestValue) variationCount++; 
            // Checks highest and lowest values
            if (itr->second > highestValue) highestValue = itr->second;
            if (itr->second < lowestValue) lowestValue = itr->second;
        } 
        for (itr = umap.begin(); itr != umap.end(); itr++)  
        {
            if (itr->second == highestValue) highestValueCount++;
            if (itr->second == lowestValue) lowestValueCount++;
        }
            // Conditions to determine whether its fixable
            if (variationCount > 2) return false;
            if (umap.size() == 1) return true;
            if (highestValue - lowestValue == 1) 
            {
                if (highestValueCount == 1) return true;
            }
            if (lowestValue == 1)
            {
                if (variationCount == 1) return true;
                else
                {
                    if (lowestValueCount == 1) return true;
                    else return false;
                }
            }
        return false;
    }
};