// convert a given list of numbers into a sorted linked list using insertion sorting technique and then insert a given value to the appropriote possition
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node *next;
}node;

node *head=NULL;

void insertion_sort(){
    if(head==NULL||head->next==NULL) return;
    node *sorted=NULL;
    node *temp=head;
    while(temp!=NULL){
        node *next=temp->next;
        if(sorted==NULL||sorted->val>=temp->val){
            temp->next=sorted;
            sorted=temp;
        }else{
            node *temp2=sorted;
            while(temp2->next!=NULL&&temp2->next->val<temp->val){
                temp2=temp2->next;
            }
            temp->next=temp2->next;
            temp2->next=temp;
        }
        temp=next;
    }
    head=sorted;
}

void createnode(int data){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->val=data;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        return;
    }
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}

void insert_newnode(int newval){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->val=newval;
    newnode->next=NULL;
    if(head==NULL||head->val>=newval){
        newnode->next=head;
        head=newnode;
        return;
    }
    node *temp=head;
    while(temp->next!=NULL&&temp->next->val<newval){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

void display(){
    node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->val);
        temp=temp->next;
    }
}

int main(){
    int input_array[]={32,99,54,63,74,25,20,19,78,28};
    int size=10;
    for(int itr=0;itr<size;itr++){
        createnode(input_array[itr]);
    }
    printf("Linked list elements before sorting: \n");
    display();
    insertion_sort();
    int nodeval=32;
    insert_newnode(nodeval);
    printf("\nLinked list elements after sorting and inserting the new element: \n");
    display();
    return 0;
}
