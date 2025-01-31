#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int val;
    struct queue *next;
}queue;

queue *qu=NULL;

void enqueue(int data){
    queue *newq=(queue *)malloc(sizeof(queue));
    newq->val=data;
    newq->next=NULL;
    if(qu==NULL){
      qu=newq;
      return ;
    }
    queue *temp=qu;
    while(temp->next!=NULL){
        temp=temp->next;
    }
   temp->next=newq;
}

int isEmpty(){
    if(qu==NULL)
      return 1;
    return 0;
}

void dequeue(){
    if(isEmpty(qu)){
        printf("stack underflow\n");
        return ;
    }
    queue *temp=qu;
    qu=qu->next;
    printf("poped value: %d\n",temp->val);
}

void peek(){
    if (!isEmpty()) 
       printf("First element in the queue: %d \n",qu->val);
    else 
        printf("empty queue \n");
}

int size(){
    int size=0;
    queue *temp=qu;
     while(temp!=NULL){
        size++;
        temp=temp->next;
    }
    return size;
}
void display(){
    printf("Elements in the queue:\n");
    queue *temp=qu;
    while(temp!=NULL){
        printf("%d ",temp->val);
        temp=temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    peek();
    dequeue();
    peek();
    printf("number of elements in the queue: %d\n",size());
    display();
    return 0;
}
