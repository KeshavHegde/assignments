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

void pop(stack *st){
    if(isEmpty(st)){
        printf("stack underflow\n");
        return ;
    }
    int temp=st->vals[st->top];
    st->top--;
    printf("poped value: %d\n",temp);
}

void display(stack *st){
    printf("Elements in the stack:\n");
    for(int i=0;i<=st->top;i++){
        printf("%d ",st->vals[i]);
    }
    printf("\n");
}
void peek(stack *st){
    printf("top element in the stack : %d\n",st->vals[st->top]);
}

int size(stack *st){
    int size=(st->top)+1;
    return size;
}

int main() {
    stack *st= (stack *)malloc(sizeof(stack));
    st->top = -1;
    push(st,10);
    push(st,20);
    push(st,30);
    peek(st);
    pop(st);
    peek(st);
    printf("number of elements in the stack: %d\n",size(st));
    display(st);
    return 0;
}
