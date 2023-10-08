#include <stdio.h>
#include <stdlib.h>

typedef struct circularQueue_{
    int* data;
    int front;
    int length;
    int rear;
} circularQueue;

circularQueue* init(int length){
    int* data_ =  (int*)calloc(length, sizeof(int));
    circularQueue* queue = (circularQueue*)malloc(sizeof(circularQueue));
    queue->data = data_;
    queue->front = -1;
    queue->rear = -1;
    queue->length = length;

    return queue;
}

int isFull(circularQueue* q);

void enqueue(int datum, circularQueue* q){
    if (q->rear==-1 && q->front==-1){
        q->rear = 0;
        q->front = 0;
        q->data[q->rear] = datum;

    }
    if (isFull(q)){
        printf("Stack is full!");
    } else {
        int trueIndex = (q->rear)%(q->length);
        q->data[trueIndex] = datum;
        q->rear++;
    }
}

int dequeue(circularQueue* q){
    if (q->front>=q->rear){
        printf("Queue is empty!");
        return -1;
    } else {
        int trueIndex = (q->front)%(q->length);
        q->front++;
        return q->data[trueIndex];
        
    }
}

int isEmpty(circularQueue* q){
    return q->rear==q->front-1;
}

int isFull(circularQueue* q){
    int trueRear = (q->rear+1)%(q->length);
    int trueFront = (q->front)%(q->length);

    return trueRear==trueFront;

}

int display(circularQueue* q){
    int i, counter=0;
    if (isEmpty(q)){
        printf("Queue is empty!\n");
        return 0;
    }
    printf("\nQueue: |");
    for (i=q->front;i<q->rear; i++){
        int trueIndex = (i)%(q->length);
        printf("%d, ", q->data[trueIndex]);
        counter++;
    }
    printf("|\n");
    int trueFront = (q->front)%(q->length);
    int trueRear = (q->rear)%(q->length);
    printf("Front: %d\n", trueFront);
    printf("Rear: %d\n", trueRear);
    printf("Length: %d\n", counter);
}


int main(){
    circularQueue* q = init(10);
    int choice;

    while (1){
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                if (isFull(q)){
                    printf("Queue is full!\n");
                } else {
                    int datum;
                    printf("Enter data: ");
                    scanf("%d", &datum);
                    enqueue(datum, q);
                }
                break;
            case 2:
                if (isEmpty(q)){
                    printf("Queue is empty!\n");
                } else {
                    printf("Dequeued: %d\n", dequeue(q));
                }
                break;
            case 3:
                display(q);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}
