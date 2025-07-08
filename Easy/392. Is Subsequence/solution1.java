class Solution {
    public boolean isSubsequence(String s, String t) {
        Stack<Character> subsequence = new Stack<>();
        for (int i = s.length()-1; i >= 0; i--) {
            subsequence.push(s.charAt(i));
        }

        for (int i = 0; i < t.length() && subsequence.size() > 0; i++) {
            if (subsequence.peek() == t.charAt(i)) subsequence.pop();
        }
        return (subsequence.size() == 0);
    }
}