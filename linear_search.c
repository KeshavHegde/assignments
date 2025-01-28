// create a linked list from a given array and search the elemets A and B and swap those elements and print the list before and after swapping the elements.
#include<stdio.h>
#include <stdlib.h>
typedef struct node{
    int val;
     struct  node *next;
}node;

node *head=NULL;

void createnode(int data){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->val=data;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        return ;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
} 

void linear_search(int A,int B){
    node* temp=head;
    int pos=0;
    int countA=0,countB=0;
    while(temp!=NULL){
        pos++;
        if(temp->val==A && countA==0){
            temp->val=B;
            countA++;
        }
        else if(temp->val==B && countB==0){
            temp->val=A;
            countB++;
        }
        if(countA && countB)
          return ;
        temp=temp->next;
    }
    return ;
}

void display(){
    node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->val);
        temp=temp->next;
    }
}

int main(){
    int input_array[]={32,32,54,63,74,25,20,19,78,20};
    int size=10;
    for(int itr=0;itr<size;itr++){
        createnode(input_array[itr]);
    }
    printf("linked list elements before swapping: ");
    display();
    int A=32,B=20;
    linear_search(A,B);
    printf("\nlinked list elements after swapping: ");
    display();
    return 0;
}
