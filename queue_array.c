 #include<stdio.h>
 #include<stdlib.h>
 #define MAX (10 + 1)

 typedef struct Queue {
     int queue[MAX];
     int front, back;
 }
 Queue;
 void createQueue(Queue * q) {
     q -> front = q -> back = 0;
 }
 void insert(Queue * q) {
     int val;
     if ((q -> front + 1) % MAX == q -> back) {
         printf("Queue is Full\n");
         return;
     }
     printf("Enter the value: ");
     scanf("%d", & val);
     q -> front = (q -> front + 1) % MAX;
     q -> queue[q -> front] = val;
     printf("Value Enqueued\n");
 }
 int serve(Queue * q) {
     int ret;
     if (q -> front == q -> back) {
         printf("Queue is Empty!\n");
         q -> front = q -> back = 0;
         return -1;
     }
     q -> back = (q -> back + 1) % MAX;
     ret = q -> queue[q -> back];
     printf("Value Dequeued\n");
     return ret;
 }

 void display(Queue * q) {
     if (q -> back == q -> front) {
         printf("Queue is Empty\n");
         return;
     }
     int temp = q -> back;
     while (temp != q -> front) {
         temp = (temp + 1) % MAX;
         printf("%d ", q -> queue[temp]);
     }
     printf("\n");
 }
 void main() {
     Queue new_que;
     Queue * q = & new_que;
     int ch, val;
     createQueue(q);
     printf("Menu:\n1: Insert\n2: Serve\n3: Display\n4: Exit\n");
     do {
         printf("Enter your choice: ");
         scanf("%d", & ch);
         switch (ch) {
         case 1:
             insert(q);
             break;
         case 2:
             serve(q);
             break;
         case 3:
             display(q);
             break;
         }
     } while (ch != 4);
 }