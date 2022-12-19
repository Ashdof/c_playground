#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    struct Node *head, *ptr;

    head = createDoublyLinkedList(head);

    ptr = addNewNodeAtEnd(head, 0);
    ptr = addNewNodeAtEnd(head, 1);
    ptr = addNewNodeAtEnd(head, 2);
    ptr = addNewNodeAtEnd(head, 3);
    ptr = addNewNodeAtEnd(head, 4);
    ptr = addNewNodeAtEnd(head, 98);
    ptr = addNewNodeAtEnd(head, 402);
    ptr = addNewNodeAtEnd(head, 1024);

    printLinkedList(head);
    printf("-----------------\n");
    insert_dnodeint_at_index(&ptr, 5, 4096);
    printLinkedList(ptr);

    freeLinkedList(ptr);
    ptr = NULL;
    return (EXIT_SUCCESS);
}
