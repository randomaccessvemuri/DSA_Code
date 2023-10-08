#include <stdio.h>
#include <stdlib.h>

/*Queue has the following functions:
    Enqueue
    Dequeue
    Display
And has the following attributes:
    front
    rear
    data
*/


typedef struct Queue_{
    int* data;
    int front;
    int length;
    int rear;
} Queue;

Queue* init(int length){
    int* data_ =  (int*)calloc(length, sizeof(int));
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = data_;
    queue->front = -1;
    queue->rear = -1;
    queue->length = length;

    return queue;
}

void enqueue(int datum, Queue* q){
    if (q->rear==-1 && q->front==-1){
        q->rear = 0;
        q->front = 0;
        q->data[q->rear] = datum;

    }
    if (q->rear==(q->length)){
        printf("Stack is full!");
    } else {
        q->data[q->rear++] = datum;
    }
}

int dequeue(Queue* q){
    if (q->front>=q->rear){
        printf("Queue is empty!");
        return -1;
    } else {
        return q->data[q->front++];
    }
}

int display(Queue* q){
    int i;
    printf("\nQueue: |");
    for (i=q->front;i<q->rear; i++){
        printf("%d, ", q->data[i]);
    }
    printf("=\n");
}

int main(){
    Queue* q = init(10);
    int choice;

while(1){
    printf("Enter your choice: \n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("Enter the number to enqueue: ");
            int datum;
            scanf("%d", &datum);
            enqueue(datum, q);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            display(q);
            break;
        case 4:
            exit(0);
            break;

        }
    }
}