#include <stdio.h>
#include <stdlib.h>
#include "ferry_loading.h"

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void enQueue(Queue* q, int length) {
    Node* newNode = malloc(sizeof(Node));
    newNode->length = length;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    }else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}



int deQueue(Queue* q) {
    if (q->front == NULL) {
        return -1;
    }

    Node* temp = q->front;
    int length = temp->length;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return length;
}


