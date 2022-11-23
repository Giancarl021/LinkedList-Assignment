#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "src/linked_list.h"

int main() {
    // Time measurements
    clock_t time_start, time_end;
    double time_taken;

    // Activity 1
    Node C = { .data = 3, .next = NULL };
    Node B = { .data = 2, .next = &C };
    Node A = { .data = 1, .next = &B };

    LinkedList list = &A;

    // Activity 2
    printList(list); // LinkedList { 1 -> 2 -> 3 -> NULL }

    // Activity 3
    printf(
        "List length: %d\n",
        lengthList(list) // O(n) complexity
    );

    // Activity 4
    list = newList(0);

    printList(list); // LinkedList { 0 -> NULL }

    for (int i = 0; i < 10; i++)
        insertOnTail(&list, i + 1);

    printList(list); // LinkedList { 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> NULL }

    insertOnHead(&list, -1);
    insertOnHead(&list, -2);
    insertOnHead(&list, -3);

    printList(list); // LinkedList { -3 -> -2 -> -1 -> 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> NULL }

    insertElement(&list, 1, 10);

    printList(list); // LinkedList { -3 -> 10 -> -2 -> -1 -> 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> NULL }

    removeElement(&list, 4);

    printList(list); // LinkedList { -3 -> 10 -> -2 -> -1 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> NULL }

    removeOnHead(&list);
    removeOnTail(&list);

    printList(list); // LinkedList { 10 -> -2 -> -1 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> NULL }

    // Activity 5
    clearList(&list); // O(n) complexity

    printList(list); // LinkedList { NULL }

    // Activity 6

    time_start = clock();

    for (int i = 0; i < 1e5; i++)
        insertOnHead(&list, i);

    time_end = clock();

    time_taken = ((double) (time_end - time_start)) / CLOCKS_PER_SEC;

    printf(
        "Time taken for 10^5 `insertOnHead` calls: %fs\n",
        time_taken // ~0.002s
    );

    clearList(&list);

    // Activity 7

    time_start = clock();

    for (int i = 0; i < 1e5; i++)
        insertOnHead(&list, i);

    insertOnTail(&list, 1e5);

    time_end = clock();

    time_taken = ((double) (time_end - time_start)) / CLOCKS_PER_SEC;

    printf(
        "Time taken for 10^5 `insertOnHead` calls with a subsequent `insertOnTail` call: %fs\n",
        time_taken // ~0.0007s (CPU optimization, probably), should be slower because the last `insertOnTail` have O(n) time complexity against the O(1) for the multiple `insertOnHead` calls
    );

    // Activity 8

    time_start = clock();

    for (int i = 0; i < 1e5; i++)
        // insertOnTail(&list, i);
        ;

    time_end = clock();

    time_taken = ((double) (time_end - time_start)) / CLOCKS_PER_SEC;

    printf(
        "Time taken for 10^5 `insertOnTail` calls: %fs\n",
        time_taken // ~30s, way slower because each `insertOnTail` have O(n) time complexity against O(1) for `insertOnHead`
    );

    clearList(&list);

    // Activity 9

    for (int i = 9; i >= 0; i--)
        insertOnHead(&list, i + 1);

    printList(list); // LinkedList { 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> NULL }

    printf(
        "Element at index %d: %d\n",
        5,
        getElement(list, 5)
    );

    // Activity 10

    printf(
        "Element at index %d: %d\n",
        6,
        getElementRecursive(list, 6)
    );

    // Activity 11

    // The best position to manipulate nodes are in the head (start) of the list. 

    return EXIT_SUCCESS;
}