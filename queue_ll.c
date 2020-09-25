#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Queue{
    Node *head, *tail;
}Queue;

void enqueue(Queue* q, int val){
    Node* n = (Node*)malloc(sizeof(Node));
    if(!n){
        printf("Not enough Memory\n");
        return NULL;
    }
    n->next = NULL;
    n->data = val;
    if((q->head == NULL) && (q->tail == NULL)){
        q->head = q->tail = n;
    }else{
        q->tail->next = n;
        q->tail = n;
    }
    printf("Value enqueued\n");
}


int dequeue(Queue *q){
    Node* temp;
    if(q->head == NULL){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        int t;
        temp = q->head;
        t = temp->data;
        q->head = q->head->next;
        free(temp);
        printf("Value popped\n");
        return t;
    }  
}
void display(Queue *q){
    Node* temp = q->head;
    while(temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->head = q->tail = NULL;
    enqueue(q, 10);
    enqueue(q, 30);
    enqueue(q, 20);
    display(q);
    dequeue(q);
    display(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    display(q);
    return 0;
}