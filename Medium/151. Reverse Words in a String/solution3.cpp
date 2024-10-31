/*
Author: hiepit
Problem: 151. Reverse Words in a String
Description: 
 - Given an input string s, reverse the order of the words.
 - A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
 - Return a string of the words in reverse order concatenated by a single space.
 - Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Note: This solution is a bit more interesting, first because its in O(1) space complexity but also because the approach is a bit exotic.
 - It works by first reversing the entire string "s".
 - Then, it iterates through s, finds the actual words and fills them properly through "s" (i.e.: taking out extra " ")
 - As each word gets filled, we then reverse them before heading to the next word
 - After every word has been properly placed and reversed inside string "s", resize "s" so that there are no extra " " at the end
 - Finally, return "s"

Here is an example "Hello World" string showcasing the steps described above:
 1- " hello world "
 2- " dlrow olleh "
 3- "dlroww olleh "
 3- "world  olleh "
 4- "world ollehh "
 5- "world hello  "
 6- "world hello"
NOTICE the string's size is kept the same at every step until the very last one in which we resize it to return

Time Complexity: O(N)
Space Complexity: O(1)

Relevent Topics: Two pointers, String
*/

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int l = 0, r = 0, i = 0, n = s.size();
        while (i < n) {
            while (i < n && s[i] != ' ')
                s[r++] = s[i++];

            if (l < r) { // if we can find a non-empty word then
                reverse(s.begin() + l, s.begin() + r); // reverse current word
                if (r == n) break;
                s[r++] = ' '; // set empty space
                l = r;
            }
            ++i; // now i == n or s[i] == ' ', so we skip that character!
        }
        if (r > 0 && s[r-1] == ' ') --r; // skip last empty character if have
        s.resize(r);
        return s;
    }
};
