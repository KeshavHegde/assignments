#include<stdio.h>
#include<stdlib.h>
#define max 10

typedef struct queue{
    int val[max];
    int rear;
}queue;

void enqueue(queue*qu,int data){
    if(qu->rear==max-1){
        printf("queue overflowing\n");
        return;
    }
    qu->val[qu->rear]=data;
    qu->rear++;
}

int isEmpty(queue*qu){
    return qu->rear==0;
}

int dequeue(queue*qu){
    if(isEmpty(qu)){
        printf("stack underflow\n");
        return -1;
    }
    int temp=qu->val[0];
    for(int itr=0;itr<qu->rear-1;itr++){
        qu->val[itr]=qu->val[itr+1];
    }
    qu->rear--;
    return temp;
}

void display(queue*qu){
    printf("Elements in the queue:\n");
    for(int itr=0;itr<qu->rear;itr++){
        printf("%d ",qu->val[itr]);
    }
    printf("\n");
}

void peek(queue*qu){
    if(isEmpty(qu))
        printf("Queue is empty\n");
    else
        printf("First element in the queue: %d\n",qu->val[0]);
}

int size(queue*qu){
    return qu->rear;
}

typedef struct stack{
    queue q;
}stack;

void initStack(stack*st){
    st->q.rear=0;
}

void push(stack*st,int data){
    enqueue(&st->q,data);
    for(int i=0;i<st->q.rear-1;i++){
        int temp=dequeue(&st->q);
        enqueue(&st->q,temp);
    }
}

int pop(stack*st){
    if(isEmpty(&st->q)){
        printf("stack underflow\n");
        return -1;
    }
    return dequeue(&st->q);
}

int main(){
    stack st;
    initStack(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    peek(&st.q);
    printf("popped value: %d\n",pop(&st));
    peek(&st.q);
    printf("number of elements in the stack: %d\n",size(&st.q));
    return 0;
}
