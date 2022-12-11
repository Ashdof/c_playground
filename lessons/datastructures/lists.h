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

void push(struct DuesPayments **head, char datePaid[], char clientName[], float amountPaid);
int countNodes(struct DuesPayments *head);
void printLinkedList(struct DuesPayments *head, int numberOfNodes);
struct DuesPayments *constructLinkedList(struct DuesPayments values, int number);
void addNewNodeAtEnd(struct DuesPayments *head, struct DuesPayments values);

#endif /* LISTS_H */
