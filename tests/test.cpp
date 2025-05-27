

#include <iostream>
#include <vector>
#include <cassert>
#include "../solutions/solution.cpp"  // Include the actual reverseList function

// Create linked list from array
ListNode* createList(const std::vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Compare two linked lists for equality
bool compareLists(ListNode* l1, ListNode* l2) {
    while (l1 && l2) {
        if (l1->val != l2->val) return false;
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1 == nullptr && l2 == nullptr;
}

// Print linked list
void printList(ListNode* head) {
    ListNode* current = head;
    std::cout << "[";
    while (current) {
        std::cout << current->val;
        if (current->next) std::cout << ", ";
        current = current->next;
    }
    std::cout << "]" << std::endl;
}

// Free linked list memory
void freeList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Run a test case with PASS/FAIL logic
void runTest(const std::vector<int>& arr, const std::vector<int>& expectedArr, const std::string& description, int& failedTests) {
    Solution solution;
    ListNode* inputList = createList(arr);
    ListNode* expectedList = createList(expectedArr);
    ListNode* resultList = solution.reverseList(inputList);  // inputList is now part of resultList

    bool passed = compareLists(resultList, expectedList);
    std::cout << "Test: " << description << std::endl;
    std::cout << "Expected: ";
    printList(expectedList);
    std::cout << "Result: ";
    printList(resultList);
    if (passed) {
        std::cout << "Result: PASSED ✅" << std::endl;
    } else {
        std::cout << "Result: FAILED ❌" << std::endl;
        ++failedTests;  // Increment failed tests counter
    }
    std::cout << "---------------------------------------------" << std::endl;

    // Free allocated memory
    freeList(expectedList);
    freeList(resultList);  // Don't free inputList separately; it's already reversed and used as resultList
}

int main() {
    int failedTests = 0;  // Counter for failed tests

    // Test cases
    runTest({1, 2}, {2, 1}, "Two elements", failedTests);
    runTest({10, 20, 30}, {30, 20, 10}, "Three increasing elements", failedTests);
    runTest({1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}, "Multiple nodes", failedTests);
    runTest({-1, -2, -3}, {-3, -2, -1}, "Negative values", failedTests);
    runTest({0, -10, 20, -30, 40}, {40, -30, 20, -10, 0}, "Mixed values", failedTests);
    runTest({5000, 10000, 15000, 20000}, {20000, 15000, 10000, 5000}, "Large positive values", failedTests);
    runTest({10, 9, 8, 7, 6}, {6, 7, 8, 9, 10}, "Decreasing order", failedTests);
    runTest({-5000}, {-5000}, "Single large negative value", failedTests);

    // Test case with large list (1 to 1000)
    std::vector<int> largeList(1000);
    for (int i = 0; i < 1000; ++i) {
        largeList[i] = i + 1;
    }
    std::vector<int> reversedLargeList(1000);
    for (int i = 0; i < 1000; ++i) {
        reversedLargeList[i] = largeList[1000 - i - 1];
    }
    runTest(largeList, reversedLargeList, "Large list (1 to 1000)", failedTests);

    // Final result
    if (failedTests > 0) {
        std::cout << "Total Failed Tests: " << failedTests << std::endl;
        return 1;  // Return non-zero to indicate failures
    } else {
        std::cout << "All tests passed successfully!" << std::endl;
        return 0;  // Return zero to indicate success
    }
}
