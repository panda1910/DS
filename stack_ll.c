#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;


typedef struct Stack{
    Node* top;
}Stack;

void createStack(Stack* s){
    s->top = NULL;
}

Node* push(Stack* s, int val){
    
    Node* n = (Node*)malloc(sizeof(Node));
    if(!n){
        printf("Stack Overflow\n");
        return NULL;
    }
    n->next = NULL;
    n->data = val;
    if(s->top != NULL){
        n->next = s->top;
    }
    s->top = n;
    printf("Value pushed\n");
    return n;
}

void peek(Stack* s){
    if(s->top == NULL) printf("Stack is empty\n");
    else printf("%d\n", s->top->data);
}

Node* pop(Stack* s){
    Node* temp;
    if(s->top == NULL){
        printf("Stack is empty\n");
        return NULL;
    }
    else{
        temp = s->top;
        s->top = s->top->next;
        printf("Value popped\n");
        return temp;
    }  
}
void display(Stack* s){
    Node* temp = s->top;
    while(temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Stack stack;
    Stack* s = &stack;
    createStack(s);
    push(s, 10);
    push(s, 20);
    display(s);
    free(pop(s));
    free(pop(s));
    push(s, 40);
    display(s);
    free(pop(s));
    return 0;
}