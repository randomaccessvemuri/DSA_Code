#include <stdio.h>
#include <stdlib.h>

typedef int Dtype;

typedef struct Node_{
    struct Node_* prev;
    Dtype data;
    struct Node_* next;
} Node;

Node* insert(Node* atNode, int datum){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = datum;
    newNode->next = atNode->next;
    newNode->prev = atNode;

    atNode->next = newNode;

    return newNode;
}

//If index is negative, we traverse backwards using the prev pointers. Else we either move forward if +ve or return same node if 0.
Node* at(Node* startNode, int index){
    Node* currentNode = startNode;
    if (index<0){
        while (index++){
            currentNode = currentNode->prev;
        }
    } else {
        while (index--){
            currentNode = currentNode->next;
        }
    }

    return currentNode;
}



void removeNode(Node* toDelete){
    //Traverse
    Node* prevNode = toDelete->prev;
    Node* nextNode = toDelete->next;

    if (prevNode!=NULL)
        prevNode->next = nextNode;
    nextNode->prev = prevNode;

    free(toDelete);
    
}

void display(Node* startNode){
    Node* currentNode = startNode;
    while (currentNode->next!=NULL){
        printf(" %p|%d| %p->",currentNode->prev, currentNode->data, currentNode->next);
        currentNode = currentNode->next;
    }
    printf("%d\n", currentNode->data);
}

//Stack definition
typedef struct Stack_{
    Node* top;
    int size;
} Stack;

//Stack functions

//Push
void push(Stack* stack, Dtype data){
    Node* newNode = insert(stack->top, data);
    stack->top = newNode;
    stack->size++;
}

//Pop
Dtype pop(Stack* stack){
    Node* topNode = stack->top;
    Dtype data = topNode->data;
    removeNode(topNode);
    stack->top = stack->top->prev;
    stack->size--;

    return data;
}

//Display
void displayStack(Stack* stack){
    display(stack->top);
}

int main(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = (Node*)malloc(sizeof(Node));
    stack->top->data = 0;
    stack->top->next = NULL;
    stack->top->prev = NULL;
    stack->size = 0;

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);

    displayStack(stack);

    pop(stack);
    pop(stack);
    pop(stack);

    displayStack(stack);

    return 0;
}