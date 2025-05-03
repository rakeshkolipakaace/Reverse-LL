// package tests;

// import solutions.Solution;
// import solutions.Solution.ListNode;  // Correct import for ListNode

// public class Test {
//     static class ReverseListTest {
//         private Solution solution = new Solution();

//         // Helper function to check if two linked lists are equal
//         private boolean listsEqual(ListNode expected, ListNode actual) {
//             while (expected != null && actual != null) {
//                 if (expected.val != actual.val) return false;
//                 expected = expected.next;
//                 actual = actual.next;
//             }
//             return expected == null && actual == null;
//         }

//         // Helper function to convert an array to a linked list
//         private ListNode createList(int[] values) {
//             if (values == null || values.length == 0) return null;
//             ListNode head = new ListNode(values[0]);
//             ListNode current = head;
//             for (int i = 1; i < values.length; i++) {
//                 current.next = new ListNode(values[i]);
//                 current = current.next;
//             }
//             return head;
//         }

//         // Helper function to print a linked list
//         private void printList(ListNode head) {
//             while (head != null) {
//                 System.out.print(head.val + " ");
//                 head = head.next;
//             }
//             System.out.println();
//         }

//         // Method to run individual tests
//         private void runTest(String testName, int[] nums, int[] expected) {
//             ListNode head = createList(nums);
//             ListNode expectedHead = createList(expected);
//             ListNode result = solution.reverseList(head);
//             boolean passed = listsEqual(expectedHead, result);
//             System.out.println(testName + ": " + (passed ? "✅ PASSED" : "❌ FAILED"));
//             if (!passed) {
//                 System.out.print("Expected: ");
//                 printList(expectedHead);
//                 System.out.print("Got: ");
//                 printList(result);
//             }
//         }

//         // Method to run all tests
//         public void runAllTests() {
//             System.out.println("Test started...");
//             runTest("Test 1", new int[]{1, 2, 3, 4, 5}, new int[]{5, 4, 3, 2, 1});
//             runTest("Test 2", new int[]{1, 2}, new int[]{2, 1});
//             runTest("Test 3", new int[]{1}, new int[]{1});
//             runTest("Test 4", new int[]{}, new int[]{});
//             runTest("Test 5", new int[]{-1, -2, -3, -4}, new int[]{-4, -3, -2, -1});
//             runTest("Test 6", new int[]{1, -2, 3, -4, 5}, new int[]{5, -4, 3, -2, 1});
//             runTest("Test 7", new int[]{-105, 0, 105}, new int[]{105, 0, -105});
//             runTest("Test 8", new int[]{0, 0, 0, 0}, new int[]{0, 0, 0, 0});
//             runTest("Test 9", new int[]{0, 1, 2, 3, 4, 5}, new int[]{5, 4, 3, 2, 1, 0});
//             runTest("Test 10", new int[]{-1, 0, 1}, new int[]{1, 0, -1});
//         }
//     }

//     public static void main(String[] args) {
//         ReverseListTest tester = new ReverseListTest();
//         tester.runAllTests();
//     }
// }







package tests;

import solutions.Solution;
import solutions.Solution.ListNode;  // Correct import for ListNode

public class Test {
    static class ReverseListTest {
        private Solution solution = new Solution();

        // Helper function to check if two linked lists are equal
        private boolean listsEqual(ListNode expected, ListNode actual) {
            while (expected != null && actual != null) {
                if (expected.val != actual.val) return false;
                expected = expected.next;
                actual = actual.next;
            }
            return expected == null && actual == null;
        }

        // Helper function to convert an array to a linked list
        private ListNode createList(int[] values) {
            if (values == null || values.length == 0) return null;
            ListNode head = new ListNode(values[0]);
            ListNode current = head;
            for (int i = 1; i < values.length; i++) {
                current.next = new ListNode(values[i]);
                current = current.next;
            }
            return head;
        }

        // Helper function to print a linked list
        private void printList(ListNode head) {
            while (head != null) {
                System.out.print(head.val + " ");
                head = head.next;
            }
            System.out.println();
        }

        // Method to run individual tests
        private void runTest(String testName, int[] nums, int[] expected) {
            ListNode head = createList(nums);
            ListNode expectedHead = createList(expected);
            ListNode result = solution.reverseList(head);
            
            // Check if the result is null, stop running if so
            if (result == null) {
                System.out.println(testName + ": ❌ FAILED (Result is null)");
                return; // Stop further execution for this test case
            }

            boolean passed = listsEqual(expectedHead, result);
            System.out.println(testName + ": " + (passed ? "✅ PASSED" : "❌ FAILED"));
            if (!passed) {
                System.out.print("Expected: ");
                printList(expectedHead);
                System.out.print("Got: ");
                printList(result);
            }
        }

        // Method to run all tests
        public void runAllTests() {
            System.out.println("Test started...");
            runTest("Test 1", new int[]{1, 2, 3, 4, 5}, new int[]{5, 4, 3, 2, 1});
            runTest("Test 2", new int[]{1, 2}, new int[]{2, 1});
            runTest("Test 3", new int[]{1}, new int[]{1});
            runTest("Test 4", new int[]{}, new int[]{});
            runTest("Test 5", new int[]{-1, -2, -3, -4}, new int[]{-4, -3, -2, -1});
            runTest("Test 6", new int[]{1, -2, 3, -4, 5}, new int[]{5, -4, 3, -2, 1});
            runTest("Test 7", new int[]{-105, 0, 105}, new int[]{105, 0, -105});
            runTest("Test 8", new int[]{0, 0, 0, 0}, new int[]{0, 0, 0, 0});
            runTest("Test 9", new int[]{0, 1, 2, 3, 4, 5}, new int[]{5, 4, 3, 2, 1, 0});
            runTest("Test 10", new int[]{-1, 0, 1}, new int[]{1, 0, -1});
        }
    }

    public static void main(String[] args) {
        ReverseListTest tester = new ReverseListTest();
        tester.runAllTests();
    }
}
