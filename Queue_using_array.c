#include <stdio.h>
#include <stdlib.h>
#define max 10
typedef struct queue{
    int val[max];
    int rear;
}queue;

void enqueue(queue *qu,int data){
    if(qu->rear==max-1){
        printf("queue overflowing\n ");
        return ;
    }
    qu->val[qu->rear]=data;
    qu->rear++;
}

int isEmpty(queue *qu){
    if(qu->rear==-1)
     return 1;
    return 0;
}

void dequeue(queue *qu){
    if(isEmpty(qu)){
        printf("stack underflow\n");
        return ;
    }
    int temp=qu->val[0];
    for(int itr=0;itr<qu->rear-1;itr++){
        qu->val[itr]=qu->val[itr+1];
    }
    qu->rear--;
    printf("poped value: %d\n",temp);
}

void display(queue *qu){
    printf("Elements in the queue:\n");
     for(int itr=0;itr<qu->rear;itr++){
        printf("%d ",qu->val[itr]);
    }
    printf("\n");
}

void peek(queue *qu){
    if(isEmpty(qu))
       printf("Queue is empty\n");
    else 
        printf("First element in the queue: %d\n",qu->val[0]);
}

int size(queue *qu){
    int size=qu->rear;
    return size;
}

int main() {
    queue *qu=(queue *)malloc(sizeof(queue));
    qu->rear=0;
    enqueue(qu,10);
    enqueue(qu,20);
    enqueue(qu,30);
    peek(qu);
    dequeue(qu);
    peek(qu);
    printf("number of elements in the queue: %d\n",size(qu));
    return 0;
}
