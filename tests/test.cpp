#include <iostream>
#include <vector>
#include <cassert>
#include "../solutions/solution.cpp"  // Include the solution file

// Create linked list from array
ListNode* createList(const std::vector<int>& arr);

// Compare two linked lists for equality
bool compareLists(ListNode* l1, ListNode* l2);

// Print linked list
void printList(ListNode* head);

// Free linked list memory
void freeList(ListNode* head);

// Run a test case with PASS/FAIL logic
void runTest(const std::vector<int>& arr, const std::vector<int>& expectedArr, const std::string& description);

int main() {
    // Test cases
    runTest({}, {}, "Empty list");
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
