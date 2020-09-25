#include<stdio.h>
#define MAX 10

typedef struct Stack{
    int arr[MAX];
    int top;
}Stack;

void push(Stack* s, int val){
    if(s->top+1 > MAX-1){
        printf("Stack is Full\n");
        return;
    }
    s->top++;
    s->arr[s->top] = val;
    printf("Value pushed\n");
}

void peek(Stack* s){
    if(s->top < 0) printf("Stack is empty\n");
    else printf("%d\n", s->arr[s->top]);
}

int pop(Stack* s){
    int t;
    if(s->top < 0) printf("Stack is empty\n");
    else{
        t = s->arr[s->top];
        s->top--;
        printf("Value popped\n");
        return t;
    }  
}
void display(Stack* s){
    if(s->top < 0) printf("Stack is empty\n");
    else{
        int i;
        for(i=0;i<=s->top;i++){
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}

int main(){
    Stack st;
    st.top = -1;
    Stack* s=&st;
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    pop(s);
    peek(s);
    display(s);
    return 0;
}