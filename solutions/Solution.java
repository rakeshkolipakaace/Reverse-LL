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
        ListNode newHead = null;
    while (head != null) {
        ListNode next = head.next;
        head.next = newHead;
        newHead = head;
        head = next;
    }
    return newHead;
        
    }
        

       // write your code here.....
    }

