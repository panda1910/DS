#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct LinkedList{
    Node *head, *tail;
    int size;
}LinkedList;

void createLinkedList(LinkedList* a){
    a->head = a->tail = NULL;
    a->size = 0;
}

void insertRight(LinkedList* a, int val){
    Node *t = (Node*)malloc(sizeof(Node));
    t->next = NULL;
    t->data = val;
    if(a->head == NULL && a->tail == NULL){
        a->head = a->tail = t;
    }else{
        a->tail->next = t;
        a->tail = t;
    }
}

void insertLeft(LinkedList* a, int val){
    Node *t = (Node*)malloc(sizeof(Node));
    t->next = NULL;
    t->data = val;
    if(a->head == NULL && a->tail == NULL){
        a->head = a->tail = t;
    }else{
        t->next = a->head;
        a->head = t;
    }
}

void display(LinkedList *a){
    Node* t = a->head;
    while(t){
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main(){
    LinkedList *a = (LinkedList*)malloc(sizeof(LinkedList));
    createLinkedList(a);
    insertRight(a, 10);
    insertRight(a, 20);
    insertRight(a, 30);
    insertLeft(a, 1);
    insertLeft(a, 2);
    insertLeft(a, 3);
    display(a);

    return 0;
}