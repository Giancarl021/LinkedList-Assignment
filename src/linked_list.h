#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#define NODE_NOT_FOUND -1e5

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef Node* LinkedList;

/// @brief Create a new Node and return a pointer to it.
/// @param data The value of the element
/// @return A pointer to a Node
Node* createNode(int data);

/// @brief Alias of createNode
/// @param initialData The value of the first element of the list
/// @return A pointer to a Node
LinkedList newList(int initialData);

/// @brief Return the value of a node given it's index on the list
/// @param list A pointer to the list
/// @return The value of the found node or NODE_NOT_FOUND if index out of bounds
int getElement(LinkedList list, int index);

int getElementRecursive(LinkedList list, int index);

/// @brief Insert a new Node at the beginning of the list.
/// @param list A pointer to the list
/// @param data The value of the new element to be added
void insertOnHead(LinkedList* list, int data);

/// @brief Insert a new Node at the end of the list.
/// @param list A pointer to the list
/// @param data The value of the new element to be added
void insertOnTail(LinkedList* list, int data);

/// @brief Insert a new Node at the given position of the list.
/// @param list A pointer to the list
/// @param position The index of the new element to be added
/// @param data The value of the new element to be added
void insertElement(LinkedList* list, int position, int data);

/// @brief Remove the first Node of the list.
/// @param list A pointer to the list
void removeOnHead(LinkedList* list);

/// @brief Remove the last Node of the list.
/// @param list A pointer to the list
void removeOnTail(LinkedList* list);

/// @brief Remove the Node at the given position of the list.
/// @param list A pointer to the list
/// @param position The index of the element to be removed
void removeElement(LinkedList* list, int position);

/// @brief Dealloc all elements of the list and set it's head to NULL
/// @param list A pointer to the list
void clearList(LinkedList *list);

/// @brief Return the number of elements in the list.
/// @param list A pointer to the list
int lengthList(LinkedList list);

/// @brief Print the Linked List
/// @param list A pointer to the list
void printList(LinkedList list);

#ifdef __cplusplus
}
#endif

#endif