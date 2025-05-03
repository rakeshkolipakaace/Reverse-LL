
// #include <stdio.h>
// #include <stdlib.h>
// #include "../solutions/solution.c"  // Include the actual reverseList function

// // Create linked list from array
// struct ListNode* createList(int* arr, int size) {
//     if (size == 0 || arr == NULL) return NULL;

//     struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
//     head->val = arr[0];
//     head->next = NULL;

//     struct ListNode* current = head;
//     for (int i = 1; i < size; i++) {
//         struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
//         node->val = arr[i];
//         node->next = NULL;
//         current->next = node;
//         current = node;
//     }
//     return head;
// }

// // Compare two linked lists for equality
// int compareLists(struct ListNode* l1, struct ListNode* l2) {
//     while (l1 && l2) {
//         if (l1->val != l2->val) return 0;
//         l1 = l1->next;
//         l2 = l2->next;
//     }
//     return l1 == NULL && l2 == NULL;
// }

// // Print linked list
// void printList(struct ListNode* head) {
//     while (head) {
//         printf("%d ", head->val);
//         head = head->next;
//     }
//     printf("\n");
// }

// // Free linked list memory
// void freeList(struct ListNode* head) {
//     while (head) {
//         struct ListNode* temp = head;
//         head = head->next;
//         free(temp);
//     }
// }

// // Run a test case with PASS/FAIL logic
// void runTest(int* arr, int size, const char* description) {
//     printf("Test: %s\n", description);

//     struct ListNode* inputList = createList(arr, size);
//     struct ListNode* outputList = reverseList(inputList);

//     // Create expected list by reversing the array
//     int* reversedArr = (int*)malloc(size * sizeof(int));
//     for (int i = 0; i < size; i++) {
//         reversedArr[i] = arr[size - i - 1];
//     }
//     struct ListNode* expectedList = createList(reversedArr, size);

//     printf("Expected: ");
//     printList(expectedList);
//     printf("Actual:   ");
//     printList(outputList);

//     if (compareLists(expectedList, outputList)) {
//         printf("Result: PASSED ✅\n\n");
//     } else {
//         printf("Result: FAILED ❌\n\n");
//         exit(1);  // Fails the test runner if even one test fails
//     }
    

//     free(reversedArr);
//     freeList(expectedList);
//     freeList(outputList);
// }

// int main() {
//     runTest(NULL, 0, "Empty list");

//     int arr1[] = {100};
//     runTest(arr1, 1, "Single node");

//     int arr2[] = {5, 10};
//     runTest(arr2, 2, "Two nodes");

//     int arr3[] = {1, 2, 3, 4, 5};
//     runTest(arr3, 5, "Multiple nodes");

//     int arr4[] = {-1, -2, -3};
//     runTest(arr4, 3, "Negative values");

//     int arr5[] = {0, -10, 20, -30, 40};
//     runTest(arr5, 5, "Mixed values");

//     int arr6[] = {5000, 10000, 15000, 20000};
//     runTest(arr6, 4, "Large positive values");

//     int arr7[] = {10, 9, 8, 7, 6};
//     runTest(arr7, 5, "Decreasing order");

//     int arr8[] = {-5000};
//     runTest(arr8, 1, "Single large negative value");

//     int arr9[1000];
//     for (int i = 0; i < 1000; i++) {
//         arr9[i] = i + 1;
//     }
//     runTest(arr9, 1000, "Large list (1 to 1000)");

//     return 0;
// }






#include <stdio.h>
#include <stdlib.h>
#include "../solutions/solution.c"  // Include your reverseList implementation

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode* next;
};

// Create linked list from array
struct ListNode* createList(int* arr, int size) {
    if (size == 0 || arr == NULL) return NULL;

    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;

    struct ListNode* current = head;
    for (int i = 1; i < size; i++) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = arr[i];
        node->next = NULL;
        current->next = node;
        current = node;
    }
    return head;
}

// Compare two linked lists for equality
int compareLists(struct ListNode* l1, struct ListNode* l2) {
    while (l1 && l2) {
        if (l1->val != l2->val) return 0;
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1 == NULL && l2 == NULL;
}

// Print linked list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Free linked list memory
void freeList(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// Run a test case
void runTest(int* arr, int size, const char* description) {
    printf("Test: %s\n", description);

    struct ListNode* inputList = createList(arr, size);
    struct ListNode* outputList = reverseList(inputList);

    // Create expected reversed list
    int* reversedArr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        reversedArr[i] = arr[size - i - 1];
    }
    struct ListNode* expectedList = createList(reversedArr, size);

    printf("Expected: ");
    printList(expectedList);
    printf("Actual:   ");
    printList(outputList);

    if (compareLists(expectedList, outputList)) {
        printf("Result: PASSED ✅\n\n");
    } else {
        printf("Result: FAILED ❌\n\n");
        exit(1);  // Stop at first failure
    }

    free(reversedArr);
    freeList(expectedList);
    freeList(outputList);
}

int main() {
    int tc1[] = {1, 2};
    runTest(tc1, 2, "Two elements");

    int tc2[] = {10, 20, 30};
    runTest(tc2, 3, "Three increasing elements");

    int tc3[] = {100, 90, 80, 70};
    runTest(tc3, 4, "Four decreasing elements");

    int tc4[] = {-1, -2, -3, -4, -5};
    runTest(tc4, 5, "Negative numbers");

    int tc5[] = {0, 1, 0, 1};
    runTest(tc5, 4, "Repeated pattern");

    int tc6[] = {5, -5, 10, -10};
    runTest(tc6, 4, "Alternating signs");

    int tc7[] = {2147483647, -2147483648};
    runTest(tc7, 2, "Extreme integer values");

    int tc8[] = {1, 3, 5, 7, 9, 11};
    runTest(tc8, 6, "Odd numbers list");

    int tc9[] = {2, 4, 6, 8, 10};
    runTest(tc9, 5, "Even numbers list");

    int tc10[] = {1000, 900, 800, 700, 600, 500};
    runTest(tc10, 6, "Descending large numbers");

    printf("All tests passed successfully! ✅\n");
    return 0;
}
