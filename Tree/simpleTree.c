#include <stdio.h>
#include <stdlib.h>
typedef int Dtype;

typedef struct Node{
    Dtype data;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* newNode(Dtype data){
    Node* res = (Node*)malloc(sizeof(Node));
    res->data = data;

    return res;
}

Node* createTree(Node* inNode){ 
    printf("\nEnter data of %p or -1 to skip: ", inNode);
    int inputData;
    scanf("%d", &inputData);

    if (inputData==-1){
        return NULL;
    } else {
        Node* parent = (Node*)malloc(sizeof(Node));
        parent->data = inputData;
        printf("\nLEFT OF %p (or -1 to ignore)", inNode);
        parent->leftChild = createTree(parent);

        printf("\nEnter right of %p (or -1 to ignore)", inNode);
        parent->rightChild = createTree(parent);
    }    
}


void inOrderTraversal(Node* inNode){
    if (inNode==NULL)
        return;
    else {
        inOrderTraversal(inNode->leftChild);
        printf("%d->", inNode->data);
        inOrderTraversal(inNode->rightChild); 
    }
}

void preOrderTraversal(Node* inNode){
    if (inNode == NULL)
        return;
    else {
        printf("%d->", inNode->data);
        preOrderTraversal(inNode->leftChild);
        preOrderTraversal(inNode->rightChild);
    }
}

void postOrderTraversal(Node* inNode){
    if (inNode == NULL) return;
    else {
        postOrderTraversal(inNode->leftChild);
        postOrderTraversal(inNode->rightChild);
        printf("%d->", inNode->data);
    }
}


Node* binarySearchTreeCreator(Dtype* inArray, Dtype num){
    Node* root = (Node*)malloc(sizeof(Node));
    root->data = inArray[0];
    for (int i = 0; i < num; i++){
        insertBST(root, inArray[i]);
    }

    return root;
}

void insertBST(Node* inNode, Dtype data){
    if (data < inNode->data){
        //LEFT SIDE
        if (inNode->leftChild==NULL){
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = data;
            inNode->leftChild = newNode;
            return;
        } else {
            insertBST(inNode->leftChild, data);
        }
    } else if (data > inNode->data){
        //RIGHT SIDE
        
         if (inNode->rightChild==NULL){
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = data;
            inNode->rightChild = newNode;
            return;
        } else {
            insertBST(inNode->rightChild, data);
        }
    }
}




int main(){
    
    int a[6] = {45,23,42,65,44,12};
    int num = 6;

    Node* root = binarySearchTreeCreator(a, num);

    inOrderTraversal(root);
    printf("\n\n");
    preOrderTraversal(root);
    printf("\n\n");
    postOrderTraversal(root);
}