#include <stdio.h>
#include <stdlib.h>

typedef char Dtype;

typedef struct node{
    Dtype data;
    struct node* next;
} Node;

Node* insert(Node* inNode, Dtype data){
    Node* ptrToNext = inNode->next;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = ptrToNext;
    inNode->next = newNode;

    return newNode;
}

int remove(Node* inNode, int relativeIndex){
    Node* currentNode = inNode;
    int i;
    for (i=0; i<relativeIndex; i++){
        currentNode = currentNode->next;
    }

    Node* ptrToNext = currentNode->next;
    currentNode->next = ptrToNext->next;
    free(ptrToNext);

    return 0;
}

//Returning new node so that for display and insertion, repeated traversal is not required if appending at the tail
Node* at(Node* head,int index){
    Node* currentNode = head;
    while (index--){
        currentNode = currentNode->next;
    }

    return currentNode;
}


void display(Node* head){
    Node* currentNode = head;
    while (currentNode->next!=NULL){
        printf("%c| %p->", currentNode->data, currentNode->next);
        currentNode = currentNode->next;
    }
    printf("%d\n", currentNode->data);
}

int main(){
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    
    Node* currentNode = head;
    //Define data here, length is calculated automatically
    int dataArray[] = {0,1,2,3,4,5};
    int len = sizeof(dataArray)/sizeof(int);
    int i;
    
    for (i=0; i<len;i++){
        currentNode = insert(currentNode,dataArray[i]);
    }



    display(head);
}