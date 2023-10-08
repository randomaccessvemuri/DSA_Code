#include "../linkedList.c"
#include <stdio.h>

typedef int Dtype;

typedef struct Queue{
    Node* head;
    Node* tail;
} Queue;


Queue* initQueue(){
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->head = (Node*)malloc(sizeof(Node));
    newQueue->tail = (Node*)malloc(sizeof(Node));
    newQueue->head->data = 0;
    newQueue->tail->data = 0;
    newQueue->head->next = newQueue->tail;
    newQueue->tail->next = NULL;

    return newQueue;
}

int enqueue(Queue* queue, Dtype data){
    Node* newNode = insert(queue->tail, data);
    queue->tail = newNode;

    return 0;
}

int dequeue(Queue* queue){
    removeNode(queue->head->next);

    return 0;
}

void displayQueue(Queue* queue){
    display(queue->head->next);
}

int main(){
    Queue* queue = initQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    displayQueue(queue);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    displayQueue(queue);

    return 0;
}