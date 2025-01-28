// convert a given list of numbers into a sorted linked list using merge sorting technique and then insert a given value to the appropriate position
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}node;

node *head=NULL;

node* findmid(node *start,node *end){
    if(start==NULL)
        return NULL;
    node *slow=start;
    node *fast=start->next;
    while(fast!=end){
        fast=fast->next;
        if(fast!=end){
            slow=slow->next;
            fast=fast->next;
        }
    }
    return slow;
}

node* merge(node *start1,node *start2){
    node *newhead=NULL,*temp=NULL;
    while(start1!=NULL && start2!=NULL){
        node *minnode;
        if(start1->val<=start2->val){
            minnode=start1;
            start1=start1->next;
        }else{
            minnode=start2;
            start2=start2->next;
        }
        if(newhead==NULL){
            newhead=minnode;
            temp=minnode;
        }else{
            temp->next=minnode;
            temp=temp->next;
        }
    }
    if(start1!=NULL){
        temp->next=start1;
        temp=temp->next;
    }else{
        temp->next=start2;
        temp=temp->next;
    }
    return newhead;
}

void merge_sort(node **start){
    if(*start==NULL||(*start)->next==NULL)
        return;
    node *middle=findmid(*start,NULL);
    node *start2=middle->next;
    middle->next=NULL;
    merge_sort(start);
    merge_sort(&start2);
    *start=merge(*start,start2);
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
    printf("\n");
}

int main(){
    int input_array[]={32,99,54,63,74,25,20,19,78,28};
    int size=10;
    for(int itr=0;itr<size;itr++){
        createnode(input_array[itr]);
    }
    printf("Linked list elements before sorting: \n");
    display();
    merge_sort(&head);
    int nodeval=39;
    insert_newnode(nodeval);
    printf("Linked list elements after sorting and inserting the new element: \n");
    display();
    return 0;
}
