#include <stdio.h>
#include <stdlib.h>
#define max 10

typedef struct stack{
    int vals[max];
    int top;
}stack;

void push(stack *st,int data){
    if(st->top==max-1){
        printf("stack overflow\n");
        return ;
    }
    st->top++;
    st->vals[st->top]=data;
}

int isEmpty(stack *st){
    if(st->top==-1)
     return 1;
    return 0;
}

int pop(stack *st){
    if(isEmpty(st)){
        printf("stack underflow\n");
        return -1;
    }
    int temp=st->vals[st->top];
    st->top--;
    return temp;
}

void display(stack *st){
    if(isEmpty(st)){
        printf("Stack is empty\n");
        return;
    }
    for(int i=0;i<=st->top;i++){
        printf("%d ",st->vals[i]);
    }
    printf("\n");
}

int size(stack *st){
    return st->top+1;
}

typedef struct queue{
    stack s;
}queue;

void initQueue(queue *q){
    q->s.top = -1;
}

void enqueue(queue *q,int data){
    push(&q->s,data);
}

int dequeue(queue *q){
    if(isEmpty(&q->s)){
        printf("Queue underflow\n");
        return -1;
    }
    stack tempStack;
    tempStack.top = -1;
    while(!isEmpty(&q->s)){
        push(&tempStack,pop(&q->s));
    }
    int dequeued = pop(&tempStack);
    while(!isEmpty(&tempStack)){
        push(&q->s,pop(&tempStack));
    }
    return dequeued;
}

int peek(queue *q){
    if(isEmpty(&q->s)){
        printf("Queue is empty\n");
        return -1;
    }
    stack tempStack;
    tempStack.top = -1;
    while(!isEmpty(&q->s)){
        push(&tempStack,pop(&q->s));
    }
    int front = tempStack.vals[tempStack.top];
    while(!isEmpty(&tempStack)){
        push(&q->s,pop(&tempStack));
    }
    return front;
}

int qsize(queue *q){
    return size(&q->s);
}

int main(){
    queue q;
    initQueue(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    printf("Peek front element: %d\n",peek(&q));
    printf("Dequeued element: %d\n",dequeue(&q));
    printf("Peek front element: %d\n",peek(&q));
    printf("Queue size: %d\n",qsize(&q));
    return 0;
}
