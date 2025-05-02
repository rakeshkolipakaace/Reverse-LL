package solutions;

public class Solution {
    
    // Definition for singly-linked list.
    public static class ListNode {
        public int val;
        public ListNode next;
        
        public ListNode(int val) {
            this.val = val;
            this.next = null;
        }
        
        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    // Function to reverse the linked list
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;  // Previous node (initially null)
        ListNode curr = head;  // Current node (starts at head)
        
        while (curr != null) {
            ListNode nextTemp = curr.next;  // Store the next node
            curr.next = prev;  // Reverse the current node's pointer
            prev = curr;  // Move prev and curr one step forward
            curr = nextTemp;
        }
        
        return prev;  // Prev will be the new head of the reversed list
    }
}
