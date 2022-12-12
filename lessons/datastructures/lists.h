#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DuesPayments
{
        float amount;
        char client[30];
        char date[10];
        struct DuesPayments *next;
};

int countNodes(struct DuesPayments *head);
void printLinkedList(struct DuesPayments *head, int numberOfNodes);
struct DuesPayments *constructLinkedList(struct DuesPayments values, int number);
void addNodeAtBeginning(struct DuesPayments **head, struct DuesPayments values);
void push(struct DuesPayments **head, char datePaid[], char clientName[], float amountPaid);
struct DuesPayments *addNewNodeAtEnd(struct DuesPayments **head, struct DuesPayments values);
struct DuesPayments *addNewNodeAtBeginning(struct DuesPayments *head, struct DuesPayments values);

#endif /* LISTS_H */
