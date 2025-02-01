#include<stdio.h>
#include<stdlib.h>
#define max 10

typedef struct queue{
    int val[max];
    int rear;
}queue;

void enqueue(queue* qu,int data){
    if(qu->rear==max-1){
        printf("queue overflowing\n");
        return;
    }
    qu->val[qu->rear]=data;
    qu->rear++;
}

int isEmpty(queue* qu){
    return qu->rear==0;
}

int dequeue(queue* qu){
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

void peek(queue* qu){
    if(isEmpty(qu))
        printf("Queue is empty\n");
    else
        printf("First element in the queue: %d\n",qu->val[0]);
}

int size(queue* qu){
    return qu->rear;
}

typedef struct stack{
    queue q1,q2;
}stack;

void initStack(stack* st){
    st->q1.rear=0;
    st->q2.rear=0;
}

void push(stack* st,int data){
    enqueue(&st->q1,data);
}

int pop(stack* st){
    if(isEmpty(&st->q1)){
        printf("stack underflow\n");
        return -1;
    }
    while(st->q1.rear>1){
        enqueue(&st->q2,dequeue(&st->q1));
    }
    int popped=dequeue(&st->q1);
    queue temp=st->q1;
    st->q1=st->q2;
    st->q2=temp;
    return popped;
}

int main(){
    stack st;
    initStack(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    peek(&st.q1);
    printf("popped value: %d\n",pop(&st));
    peek(&st.q1);
    printf("number of elements in the stack: %d\n",size(&st.q1));
    return 0;
}
