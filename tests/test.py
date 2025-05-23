# import unittest
# import sys
# import os

# # Ensure Python finds the 'solutions' folder where solution.py is located
# sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'solutions')))

# from solution import Solution  # Importing the Solution class from solution.py

# # Define the ListNode class
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# class TestReverseLinkedList(unittest.TestCase):

#     # Helper function to convert list to linked list
#     def list_to_linkedlist(self, elements):
#         head = ListNode(0)
#         current = head
#         for number in elements:
#             current.next = ListNode(number)
#             current = current.next
#         return head.next

#     # Helper function to convert linked list to list
#     def linkedlist_to_list(self, node):
#         result = []
#         while node:
#             result.append(node.val)
#             node = node.next
#         return result

#     def setUp(self):
#         self.solution = Solution()

#     def test_reverse_list(self):
#         test_cases = [
#             # 1. Empty list
#             ([], []),
#             # 2. Single element
#             ([1], [1]),
#             # 3. Two elements
#             ([1, 2], [2, 1]),
#             # 4. Odd number of elements
#             ([1, 2, 3], [3, 2, 1]),
#             # 5. Even number of elements
#             ([10, 20, 30, 40], [40, 30, 20, 10]),
#             # 6. Negative numbers
#             ([-5, -3, -1], [-1, -3, -5]),
#             # 7. Including zero
#             ([0, 1, 2, 3], [3, 2, 1, 0]),
#             # 8. Duplicates
#             ([2, 2, 3, 3], [3, 3, 2, 2]),
#             # 9. Long list (length = 10)
#             ([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]),
#             # 10. Mixed positives and negatives
#             ([-2, 0, 3, -1, 4], [4, -1, 3, 0, -2])
#         ]

#         for i, (input_list, expected_output) in enumerate(test_cases):
#             print(f"Running Test {i + 1}")
#             print(f"Input: {input_list}")
#             print(f"Expected Output: {expected_output}")
#             head = self.list_to_linkedlist(input_list)
#             reversed_head = self.solution.reverseList(head)
#             result = self.linkedlist_to_list(reversed_head)
#             print(f"Actual Output: {result}")
#             self.assertEqual(result, expected_output)
#             print(f"Test {i + 1}: ✅ PASSED")

# if __name__ == "__main__":
#     unittest.main()





import sys
import os

# Ensure Python finds the 'solutions' folder where solution.py is located
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'solutions')))

from solution import Solution  # Importing the Solution class from solution.py

# Define ListNode if not already defined in solution.py
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Helper function to convert a list to a linked list
def list_to_linkedlist(elements):
    head = ListNode(0)
    current = head
    for number in elements:
        current.next = ListNode(number)
        current = current.next
    return head.next

# Helper function to convert linked list to list
def linkedlist_to_list(node):
    result = []
    while node:
        result.append(node.val)
        node = node.next
    return result

# Helper function to run a single test
def run_test(test_name, input_list, expected_output, solution):
    head = list_to_linkedlist(input_list)
    expected_head = list_to_linkedlist(expected_output)
    result_head = solution.reverseList(head)
    result_list = linkedlist_to_list(result_head)
    passed = result_list == expected_output

    if passed:
        print(f"{test_name}: ✅ PASSED")
    else:
        print(f"{test_name}: ❌ FAILED")
        print(f"  Input: {input_list}")
        print(f"  Expected: {expected_output}")
        print(f"  Got: {result_list}")
    return passed

def main():
    solution = Solution()
    test_cases = [
        ("Test 1", [1, 2, 3, 4, 5], [5, 4, 3, 2, 1]),
        ("Test 2", [1, 2], [2, 1]),
        ("Test 3", [1], [1]),
        ("Test 4", [], []),
        ("Test 5", [-1, -2, -3, -4], [-4, -3, -2, -1]),
        ("Test 6", [1, -2, 3, -4, 5], [5, -4, 3, -2, 1]),
        ("Test 7", [-105, 0, 105], [105, 0, -105]),
        ("Test 8", [0, 0, 0, 0], [0, 0, 0, 0]),
        ("Test 9", [0, 1, 2, 3, 4, 5], [5, 4, 3, 2, 1, 0]),
        ("Test 10", [-1, 0, 1], [1, 0, -1]),
    ]

    all_passed = True
    for name, inp, expected in test_cases:
        passed = run_test(name, inp, expected, solution)
        all_passed &= passed

    if not all_passed:
        sys.exit(1)  # Fail the GitHub Actions workflow

if __name__ == "__main__":
    main()
