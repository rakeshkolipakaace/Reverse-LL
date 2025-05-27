
package tests;

import solutions.Solution;
import solutions.Solution.ListNode;

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
        private boolean runTest(String testName, int[] nums, int[] expected) {
            ListNode head = createList(nums);
            ListNode expectedHead = createList(expected);
            ListNode result = solution.reverseList(head);

            // Handle case where both are null (empty list)
            if (expectedHead == null && result == null) {
                System.out.println(testName + ": ✅ PASSED");
                return true;
            }

            // If result is null but expected is not
            if (result == null) {
                System.out.println(testName + ": ❌ FAILED (Result is null, expected non-null)");
                return false;
            }

            boolean passed = listsEqual(expectedHead, result);
            System.out.println(testName + ": " + (passed ? "✅ PASSED" : "❌ FAILED"));
            if (!passed) {
                System.out.print("Expected: ");
                printList(expectedHead);
                System.out.print("Got: ");
                printList(result);
            }
            return passed;
        }

        // Method to run all tests and return whether all passed
        public boolean runAllTests() {
            System.out.println("Test started...");
            boolean allPassed = true;

            allPassed &= runTest("Test 1", new int[]{1, 2, 3, 4, 5}, new int[]{5, 4, 3, 2, 1});
            allPassed &= runTest("Test 2", new int[]{1, 2}, new int[]{2, 1});
            allPassed &= runTest("Test 3", new int[]{1}, new int[]{1});
            allPassed &= runTest("Test 4", new int[]{}, new int[]{}); // fixed case
            allPassed &= runTest("Test 5", new int[]{-1, -2, -3, -4}, new int[]{-4, -3, -2, -1});
            allPassed &= runTest("Test 6", new int[]{1, -2, 3, -4, 5}, new int[]{5, -4, 3, -2, 1});
            allPassed &= runTest("Test 7", new int[]{-105, 0, 105}, new int[]{105, 0, -105});
            allPassed &= runTest("Test 8", new int[]{0, 0, 0, 0}, new int[]{0, 0, 0, 0});
            allPassed &= runTest("Test 9", new int[]{0, 1, 2, 3, 4, 5}, new int[]{5, 4, 3, 2, 1, 0});
            allPassed &= runTest("Test 10", new int[]{-1, 0, 1}, new int[]{1, 0, -1});

            return allPassed;
        }
    }

    public static void main(String[] args) {
        ReverseListTest tester = new ReverseListTest();
        boolean passed = tester.runAllTests();
        if (!passed) {
            System.exit(1);  // Fail the GitHub Action job
        }
    }
}
