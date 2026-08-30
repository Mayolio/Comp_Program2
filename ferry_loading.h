#ifndef HEADER_H
#define HEADER_H

typedef struct Node {
    int length;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void enQueue(Queue*, int);

int deQueue(Queue*);

int isEmpty(Queue*);

#endif //HEADER_H
