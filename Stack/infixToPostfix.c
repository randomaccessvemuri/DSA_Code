#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Stack implementation first:

typedef struct Stack_{
    int top;
    int length;
    char* data;
} Stack;

Stack* init(int length_){
    Stack* res = (Stack*)malloc(sizeof(Stack));
    res->length = length_;
    res->top = -1;

    char* data_ = (char*)calloc(length_, sizeof(char));
    res->data = data_;

    return res;
}

void pushInStack(char datum, Stack* inStack){
    if (inStack->top<inStack->length)
       inStack->data[++inStack->top] = datum;
    else
        printf("\nStack is full!\n");
}

char popInStack(Stack* inStack){
    if (inStack->top!=-1){
        return inStack->data[inStack->top--];
    } else {
        printf("\nStack is empty!\n");
    }
}

void displayStack(Stack* inStack){
    int i;
    printf("\nStack: |");
    for (i=0;i<=inStack->top; i++){
        printf("%c, ", inStack->data[i]);
    }
    printf("=\n");
}

int precedence(char op){
    switch(op){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default: 
            return 0;

    }
}

char getTop(Stack* stack){
    return stack->data[stack->top];
}

int isOperand(char op){
    return (op>='a' && op<='z') || (op>='A' && op<='Z');
}

char* infixToPostfix(char* infix){
    int postfixLen = strlen(infix);
    Stack* stk = init(postfixLen);
    char* postfix = (char*)calloc(postfixLen, sizeof(char));

    int i=0, j=0;
    while (infix[i]!='\0'){
        if (isOperand(infix[i])){
            printf("I'm here");
            postfix[j++] = infix[i];
        } else if (infix[i]=='('){
            pushInStack(infix[i], stk);
        } else if (infix[i]==')'){
            char currentChar = ')';
            while (currentChar!='('){
                currentChar = popInStack(stk);
                if (currentChar!='(')
                    postfix[j++] = currentChar;        
            }
        } else {
                //Precedence check
                if (stk->top==-1){
                    pushInStack(infix[i], stk);
                }
                else if (precedence(getTop(stk))>=precedence(infix[i])){
                    postfix[j++] = popInStack(stk);
                    pushInStack(infix[i], stk);
                } else {
                    pushInStack(infix[i], stk);
                }
            }
        i++; 
        }



        while (stk->top!=-1){
            postfix[j++] = popInStack(stk);
        }

        postfix[j++] = '\0';

        return postfix;
}


int main(){
    char* infix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    

    char* postfix = infixToPostfix(infix);
    printf("Postfix expression: %s\n", postfix);
}



