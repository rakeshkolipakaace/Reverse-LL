import unittest
from solution import Solution  # Importing the Solution class from solution.py

class TestReverseLinkedList(unittest.TestCase):

    # Helper function to convert list to linked list
    def list_to_linkedlist(self, elements):
        head = ListNode(0)
        current = head
        for number in elements:
            current.next = ListNode(number)
            current = current.next
        return head.next

    # Helper function to convert linked list to list
    def linkedlist_to_list(self, node):
        result = []
        while node:
            result.append(node.val)
            node = node.next
        return result

    def setUp(self):
        self.solution = Solution()

    def test_reverse_list(self):
        test_cases = [
            # 1. Empty list
            ([], []),
            # 2. Single element
            ([1], [1]),
            # 3. Two elements
            ([1, 2], [2, 1]),
            # 4. Odd number of elements
            ([1, 2, 3], [3, 2, 1]),
            # 5. Even number of elements
            ([10, 20, 30, 40], [40, 30, 20, 10]),
            # 6. Negative numbers
            ([-5, -3, -1], [-1, -3, -5]),
            # 7. Including zero
            ([0, 1, 2, 3], [3, 2, 1, 0]),
            # 8. Duplicates
            ([2, 2, 3, 3], [3, 3, 2, 2]),
            # 9. Long list (length = 10)
            ([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]),
            # 10. Mixed positives and negatives
            ([-2, 0, 3, -1, 4], [4, -1, 3, 0, -2])
        ]

        for i, (input_list, expected_output) in enumerate(test_cases):
            print(f"Running Test {i + 1}")
            print(f"Input: {input_list}")
            print(f"Expected Output: {expected_output}")
            head = self.list_to_linkedlist(input_list)
            reversed_head = self.solution.reverseList(head)
            result = self.linkedlist_to_list(reversed_head)
            print(f"Actual Output: {result}")
            self.assertEqual(result, expected_output)
            print(f"Test {i + 1}: ✅ PASSED")

if __name__ == "__main__":
    unittest.main()
