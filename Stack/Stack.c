#include <stdio.h>
#include <stdlib.h>

//top is the pointer to the top most element which is where the operations take place. The data array is just a pointer so that the init function can take variable length input
typedef struct Stack_{
    int top;
    int length;
    int* data;
} Stack;

Stack* init(int length_){
    Stack* res = (Stack*)malloc(sizeof(Stack));
    res->length = length_;
    res->top = -1;

    int* data_ = (int*)calloc(length_, sizeof(int));
    res->data = data_;

    return res;
}

void pushInStack(int datum, Stack* inStack){
    if (inStack->top<inStack->length)
       inStack->data[++inStack->top] = datum;
    else
        printf("\nStack is full!\n");
}

int popFromStack(Stack* inStack){
    if (inStack->top!=-1){
        return inStack->data[inStack->top--];
    } else {
        printf("\nStack is empty!\n");
        return -1;
    }
}

void displayStack(Stack* inStack){
    int i;
    printf("\nStack: |");
    for (i=0;i<=inStack->top; i++){
        printf("%d, ", inStack->data[i]);
    }
    printf("=\n");
}

int main(){
    Stack* stk = init(10);

    while (1){
        printf("Enter your choice: \n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n Your choice:");
        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter number to push: ");
                int num;
                scanf("%d", &num);
                pushInStack(num, stk);
                break;
            case 2:
                int numOut = popFromStack(stk);
                printf("Number removed: %d", numOut);
                break;
            case 3:
                displayStack(stk);
                break;
            case 4:
                exit(0);
        }
    }

    return 0;
}



