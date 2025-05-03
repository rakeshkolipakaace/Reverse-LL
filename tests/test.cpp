#include <iostream>
#include <vector>
#include <cassert>
#include "../solutions/solution.cpp"  // Include the solution file

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
void runTest(const std::vector<int>& arr, const std::vector<int>& expectedArr, const std::string& description) {
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
    std::cout << (passed ? "✅ Test Passed!" : "❌ Test Failed!") << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    // Free allocated memory
    freeList(expectedList);
    freeList(resultList);  // Don't free inputList separately; it's already reversed and used as resultList
}


int main() {
    // Test cases
    
    runTest({100}, {100}, "Single node");
    runTest({5, 10}, {10, 5}, "Two nodes");
    runTest({1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}, "Multiple nodes");
    runTest({-1, -2, -3}, {-3, -2, -1}, "Negative values");
    runTest({0, -10, 20, -30, 40}, {40, -30, 20, -10, 0}, "Mixed values");
    runTest({5000, 10000, 15000, 20000}, {20000, 15000, 10000, 5000}, "Large positive values");
    runTest({10, 9, 8, 7, 6}, {6, 7, 8, 9, 10}, "Decreasing order");
    runTest({-5000}, {-5000}, "Single large negative value");

    // Test case with large list (1 to 1000)
    std::vector<int> largeList(1000);
    for (int i = 0; i < 1000; ++i) {
        largeList[i] = i + 1;
    }
    std::vector<int> reversedLargeList(1000);
    for (int i = 0; i < 1000; ++i) {
        reversedLargeList[i] = largeList[1000 - i - 1];
    }
    runTest(largeList, reversedLargeList, "Large list (1 to 1000)");

    return 0;
}
