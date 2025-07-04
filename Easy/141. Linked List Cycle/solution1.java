/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while (true) {
            if (fast == null || fast.next == null || fast.next.next == null) break;
            slow = slow.next;
            fast = fast.next.next;
            
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
}