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

int main(){
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    head->prev = NULL;
    
    Node* currentNode = head;
    //Define data here, length is calculated automatically
    int dataArray[] = {0,1,2,3,4,5};
    int len = sizeof(dataArray)/sizeof(int);
    int i;
    
    for (i=0; i<len;i++){
        currentNode = insert(currentNode,dataArray[i]);
    }

    printf("\nBEFORE REMOVE:\n");
    display(head);
    removeNode(at(head, 1));
    printf("\nAFTER REMOVE:\n");
    display(head);
    removeNode(at(head, 3));
    display(head);
}