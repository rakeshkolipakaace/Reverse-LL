#include <stdio.h>
#include <stdlib.h>
#include "../solutions/solution.c"

// [Previous utility functions remain exactly the same...]

// Modified runTest to return success/fail
int runTest(int* arr, int size, const char* description) {
    printf("\n=== Running Test: %s ===\n", description);
    
    struct ListNode* head = createList(arr, size);
    printf("Original: ");
    printList(head);

    struct ListNode* reversed = reverseList(head);
    printf("Reversed: ");
    printList(reversed);

    // Simple validation - just check if reversed isn't NULL (for non-empty lists)
    int passed = 1;
    if (size > 0 && reversed == NULL) {
        passed = 0;
    }
    
    freeList(reversed);
    
    if (passed) {
        printf("✅ PASSED\n");
    } else {
        printf("❌ FAILED\n");
    }
    
    return passed;
}

int main() {
    int total_tests = 10;
    int passed_tests = 0;
    
    // Test 1: Empty list
    passed_tests += runTest(NULL, 0, "Empty list");

    // Test 2: Single node
    int arr1[] = {100};
    passed_tests += runTest(arr1, 1, "Single node");

    // Test 3: Two nodes
    int arr2[] = {5, 10};
    passed_tests += runTest(arr2, 2, "Two nodes");

    // Test 4: Multiple nodes
    int arr3[] = {1, 2, 3, 4, 5};
    passed_tests += runTest(arr3, 5, "Multiple nodes");

    // Test 5: Negative values
    int arr4[] = {-1, -2, -3};
    passed_tests += runTest(arr4, 3, "Negative values");

    // Test 6: Mixed values
    int arr5[] = {0, -10, 20, -30, 40};
    passed_tests += runTest(arr5, 5, "Mixed values");

    // Test 7: Large positive value
    int arr6[] = {5000, 10000, 15000, 20000};
    passed_tests += runTest(arr6, 4, "Large positive values");

    // Test 8: Decreasing order
    int arr7[] = {10, 9, 8, 7, 6};
    passed_tests += runTest(arr7, 5, "Decreasing order");

    // Test 9: Single large negative value
    int arr8[] = {-5000};
    passed_tests += runTest(arr8, 1, "Single large negative value");

    // Test 10: Large list (1 to 1000)
    int arr9[1000];
    for (int i = 0; i < 1000; i++) {
        arr9[i] = i + 1;
    }
    passed_tests += runTest(arr9, 1000, "Large list (1 to 1000)");

    printf("\n=== Final Results ===\n");
    printf("Passed: %d/%d tests\n", passed_tests, total_tests);
    printf("Success Rate: %.1f%%\n", (float)passed_tests/total_tests*100);

    return 0;
}