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

void createList(LinkedList* a){
    a->head = a->tail = NULL;
    a->size = 0;
}

void insert(LinkedList* a, int index,int val){
    if(index > a->size){
        printf("List index out of range\n");
        return;
    }
    Node* temp;
    Node*t = (Node*)malloc(sizeof(Node));
    t->data = val;
    t->next = NULL;
    if((a->head == NULL) && (a->tail ==  NULL)){
        a->head = a->tail = t;
        a->size++;
    }else{
        temp = a->head;
        if(index == 0){
            t->next = a->head;
            a->head = t;
            a->size++;
        }else{
            Node* after;
            int count = 1;
            while(count != index){
                temp = temp->next;
                count++;
            }
            after = temp->next;
            temp->next = t;
            t->next = after;
            a->size++;
        }
    }
    printf("Value inserted\n");
}

int Delete(LinkedList *a, int index){
    Node* t, *x;
    int temp;
    if(a->size == 0){
        printf("List is empty\n");
        return -1;
    }
    if(index > a->size || index < 0){
        printf("List index out of range\n");
        return -1;
    }
    if(index == 0){
        t = a->head;
        a->head = a->head->next;
    }else{
        x = a->head;
        int count = 1;
        while(count != index){
            x = x->next;
            count++;
        }
        t = x->next;
        x->next = t->next;
        
    }
    temp = t->data;
    free(t);
    a->size--;
    printf("Value Deleted\n");
    return temp;
}

void display(LinkedList* a){
    if(a->size == 0) return;
    Node* t = a->head;
    while(t){
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}


int main(){
    LinkedList list;
    LinkedList* a = &list;
    createList(a);
    insert(a, 0, 10);
    insert(a, 0, -9);
    insert(a, 2, 12);
    insert(a, 3, 40);
    insert(a, 10, 99);
    display(a);
    Delete(a, 2);
    display(a);
    printf("size: %d\n", a->size);
    Delete(a, 0);
    Delete(a, 0);
    display(a);
    Delete(a, 0);
    printf("size: %d\n", a->size);
    return 0;
}