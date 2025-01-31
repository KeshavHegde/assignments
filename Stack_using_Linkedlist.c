#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int val;
    struct stack *next;
}stack;

stack *st_head=NULL;

void push(int data){
    stack *temp=(stack*)malloc(sizeof(stack));
    temp->val=data;
    temp->next=st_head;
    st_head=temp;
}

int isEmpty(){
    if(st_head==NULL)
     return 1;
    return 0;
}

void pop(){
    if(isEmpty()){
        printf("stack underflow\n");
        return ;
    }
    stack *temp=st_head;
    st_head=st_head->next;
    printf("poped value: %d\n",temp->val);
}

void display(){
    printf("Elements in the stack:\n");
    stack *temp=st_head;
    while(temp!=NULL){
        printf("%d ",temp->val);
        temp=temp->next;
    }
    printf("\n");
}
void peek(){
    printf("top element in stack :%d \n",st_head->val);
}

int size(){
    int size=0;
    stack *temp=st_head;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }
    return size;
}

int main() {
    push(10);
    push(20);
    push(30);
    peek();
    pop();
    peek();
    printf("number of elements in the stack: %d\n",size());
    display();
    return 0;
}
