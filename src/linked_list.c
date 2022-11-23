#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/// @brief Create a new Node and return a pointer to it.
/// @param data The value of the element
/// @return A pointer to a Node
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->data = data;
    node->next = NULL;

    return node;
}

/// @brief Alias of createNode
/// @param initialData The value of the first element of the list
/// @return A pointer to a Node
LinkedList newList(int initialData) {
    return createNode(initialData);
}

/// @brief Return the value of a node given it's index on the list
/// @param list A pointer to the list
/// @param index The index of the element to be found
/// @return The value of the found node or NODE_NOT_FOUND if index out of bounds
int getElement(LinkedList list, int index) {
    int i = 0;
    Node* current = list;
    
    if (index < 0) return NODE_NOT_FOUND;

    while ((i++) < index) {
        current = current->next;
        if (current == NULL) return NODE_NOT_FOUND;
    }

    return current->data;
}

/// @brief Return the value of a node given it's index on the list using a recursive approach
/// @param list A pointer to the list
/// @param index The index of the element to be found
/// @return The value of the found node or NODE_NOT_FOUND if index out of bounds
int getElementRecursive(LinkedList list, int index) {
    if (index < 0 || list == NULL) return NODE_NOT_FOUND;
    if (index == 0) return list->data;

    return getElementRecursive(list->next, index - 1);
}

/// @brief Insert a new Node at the beginning of the list.
/// @param list A pointer to the list
/// @param data The value of the new element to be added
void insertOnHead(LinkedList* list, int data) {
    Node* node = createNode(data);

    node->next = *list;
    *list = node;
}

/// @brief Insert a new Node at the end of the list.
/// @param list A pointer to the list
/// @param data The value of the new element to be added
void insertOnTail(LinkedList* list, int data) {
    Node* node = createNode(data);

    if (*list == NULL) {
        *list = node;
        return;
    }

    Node* current = *list;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = node;
}

/// @brief Insert a new Node at the given position of the list.
/// @param list A pointer to the list
/// @param position The index of the new element to be added
/// @param data The value of the new element to be added
void insertElement(LinkedList* list, int position, int data) {
    if (position == 0) {
        insertOnHead(list, data);
        return;
    }

    Node* node = createNode(data);

    Node* current = *list;

    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }

    node->next = current->next;
    current->next = node;
}

/// @brief Remove the first Node of the list.
/// @param list A pointer to the list
void removeOnHead(LinkedList* list) {
    if (*list == NULL) {
        return;
    }

    Node* node = *list;

    *list = node->next;

    free(node);
}

/// @brief Remove the last Node of the list.
/// @param list A pointer to the list
void removeOnTail(LinkedList* list) {
    if (*list == NULL) {
        return;
    }

    Node* current = *list;

    if (current->next == NULL) {
        free(current);
        *list = NULL;
        return;
    }

    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

/// @brief Remove the Node at the given position of the list.
/// @param list A pointer to the list
/// @param position The index of the element to be removed
void removeElement(LinkedList* list, int position) {
    if (position == 0) {
        removeOnHead(list);
        return;
    }

    Node* current = *list;

    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }

    Node* node = current->next;

    current->next = node->next;

    free(node);
}

/// @brief Dealloc all elements of the list and set it's head to NULL
/// @param list A pointer to the list
void clearList(LinkedList *list) {
    Node* current = *list;
    Node* tmp;
    
    if (current == NULL) return;

    while (current->next != NULL) {
        tmp = current->next;
        free(current);
        current = tmp;
    }

    free(current);

    *list = NULL;
}

/// @brief Return the number of elements in the list.
/// @param list A pointer to the list
int lengthList(LinkedList list) {
    int length = 0;
    Node* current = list;

    while (current != NULL) {
        length++;
        current = current->next;
    }

    return length;
}

/// @brief Print the Linked List
/// @param list A pointer to the list
void printList(LinkedList list) {
    Node* current = list;

    printf("LinkedList { ");

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL }\n");
}