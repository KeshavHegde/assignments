// create a linked list from a given array and swap edge datas one by one and print final list   
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}node;

node *head=NULL;

void createnode(int* input,int size){
    int itr=0;
    while(itr<size){
        node* newnode=(node*)malloc(sizeof(node));
        newnode->data=input[itr];
        newnode->next=NULL;
        newnode->prev=NULL;
        if(head==NULL){
            head=newnode;
        }else{
            node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;
        }
        itr++;
    }
}

void swapit(){
    if(head==NULL||head->next==NULL){
        return;
    }
    node* temp1=head;
    node* temp2=head;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    while(temp1!=temp2&&temp1->prev!=temp2){
        int temp=temp1->data;
        temp1->data=temp2->data;
        temp2->data=temp;
        temp1=temp1->next;
        temp2=temp2->prev;
    }
}

void display(){
    node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    int input_array[]={1,2,3,4,5,6,7,8,9,10};
    int size=10;
    createnode(input_array,size);
    printf("Before swapping the list:\n");
    display();
    swapit();
    printf("After swapping the list:\n");
    display();
    return 0;
}
