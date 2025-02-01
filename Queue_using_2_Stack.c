#include <stdio.h>
#include <stdlib.h>
#define max 10

typedef struct stack{
    int vals[max];
    int top;
}stack;

void push(stack *st, int data) {
    if (st->top == max - 1) {
        printf("stack overflow\n");
        return;
    }
    st->top++;
    st->vals[st->top] = data;
}

int isEmpty(stack *st) {
    if (st->top == -1)
        return 1;
    return 0;
}

int pop(stack *st) {
    if (isEmpty(st)) {
        printf("stack underflow\n");
        return -1;
    }
    int temp = st->vals[st->top];
    st->top--;
    return temp;
}

int size(stack *st) {
    return st->top + 1;
}

typedef struct queue {
    stack s1, s2;
} queue;

void initQueue(queue *q) {
    q->s1.top = -1;
    q->s2.top = -1;
}

void enqueue(queue *q, int data) {
    push(&q->s1, data);
}

int dequeue(queue *q) {
    if (isEmpty(&q->s1) && isEmpty(&q->s2)) {
        printf("Queue underflow\n");
        return -1;
    }
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            push(&q->s2, pop(&q->s1));
        }
    }
    return pop(&q->s2);
}

int peek(queue *q) {
    if (isEmpty(&q->s1) && isEmpty(&q->s2)) {
        printf("Queue is empty\n");
        return -1;
    }
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            push(&q->s2, pop(&q->s1));
        }
    }
    return q->s2.vals[q->s2.top];
}

int queueSize(queue *q) {
    return size(&q->s1) + size(&q->s2);
}

int main() {
    queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("Peek front element: %d\n", peek(&q));
    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Peek front element: %d\n", peek(&q));
    printf("Queue size: %d\n", queueSize(&q));
    return 0;
}
