// Design, develop, and execute a program in C to simulate the working of a queue of integers using an array.
// Provide the following operations: a. Insert b. Delete c. Display

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int QUEUE[MAX];
int REAR = -1;
int FRONT = -1;

void enqueue(int val){
    if(REAR == MAX - 1){
        printf("Queue is Full\n");
        return;
    }
    if(FRONT == -1){
        FRONT = 0;
    }
    QUEUE[++REAR] = val;
    printf("\n Item Inserted to Queue\n");
}

void dequeue(){
    if(FRONT == -1 || FRONT > REAR){
        printf("Queue is Empty\n");
        return;
    }
    int item = QUEUE[FRONT++];
    printf("\n Delete: %d", item);
}

void display(){
    if(FRONT == -1 || FRONT > REAR){
        printf("Queue is Empty\n");
        return;
    }
    printf("\n Queue: \t");
    for(int i = FRONT; i <= REAR; i++){
        printf("%d\t", QUEUE[i]);
    }
    printf("\n");
}

void main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();
}