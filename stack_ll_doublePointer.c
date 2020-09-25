#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void push(Node**s, int val){
    Node* n = (Node*)malloc(sizeof(Node));
    if(!n){
        printf("Stack Overflow\n");
        return NULL;
    }
    n->next = NULL;
    n->data = val;
    if((*s) != NULL){
        n->next = (*s);
    }
    (*s) = n;
    printf("Value pushed\n");

}

void peek(Node** s){
    if((*s) == NULL) printf("Stack is empty\n");
    else printf("%d\n", (*s)->data);
}

void pop(Node** s){
    Node* temp;
    if((*s) == NULL){
        printf("Stack is empty\n");
    }
    else{
        temp = (*s);
        (*s) = (*s)->next;
        printf("Value popped\n");
        free(temp);
    }  
}
void display(Node** s){
    Node* temp = (*s);
    while(temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Node *f = NULL;
    push(&f, 10);
    display(&f);
    push(&f, 20);
    push(&f, 30);
    push(&f, 50);
    pop(&f);
    pop(&f);
    display(&f);
    pop(&f);
    pop(&f);pop(&f);
    return 0;
}