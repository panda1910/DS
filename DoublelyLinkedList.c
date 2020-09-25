#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
}Node;

typedef struct DoublelinkList{
    Node *head, *tail;
    int size;
}DoublelinkList;

void createList(DoublelinkList* a){
    a->head = a->tail = NULL;
    a->size = 0;
}
void insert(DoublelinkList* a, int index, int val){
    if(index > a->size){
        printf("List index out of range\n");
        return;
    }
    Node* temp;
    Node*t = (Node*)malloc(sizeof(Node));
    t->data = val;
    t->next = t->prev = NULL;
    if((a->head == NULL) && (a->tail ==  NULL)){
        a->head = a->tail = t;
        a->size++;
    }else{
        temp = a->head;
        if(index == 0){
            t->next = a->head;
            a->head->prev = t;
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
            t->prev = temp;
            t->next = after;
            after->prev = t;
            a->size++;
        }
    }
    printf("Value inserted\n");
}


int Delete(DoublelinkList *a, int index){
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
        a->head->prev = NULL;
    }else{
        x = a->head;
        int count = 1;
        while(count != index){
            x = x->next;
            count++;
        }
        t = x->next;
        x->next = t->next;
        t->next->prev = x;
    }
    temp = t->data;
    free(t);
    a->size--;
    printf("Value Deleted\n");
    return temp;
}

void display(DoublelinkList* a){
    if(a->size == 0) return;
    Node* t = a->head;
    while(t){
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}
void displayRev(DoublelinkList* a){
    if(a->size == 0) return;
    Node* t = a->head;
    while(t){
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main(){
    DoublelinkList *a = (DoublelinkList*)malloc(sizeof(DoublelinkList));
    createList(a);
    insert(a, 0, 10);
    insert(a, 0, 12);
    insert(a, 1, 99);
    display(a);
    Delete(a, 1);
    Delete(a, 0);
    display(a);

    return 0;
}