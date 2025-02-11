#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    char data;
    struct node* next;
}node;

node *head=NULL;

void createnode(char * data){
    for(int itr=0;itr<strlen(data);itr++){
        node *newnode=(node * )malloc(sizeof(node));
        newnode->data=data[itr];
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
        }else{
            node *temp=head;
            while(temp->next !=NULL){
                temp=temp->next;
            }temp->next=newnode;
        }
    }
}
node *findmid(){
    node *slow=head;
    node *fast=head->next;
    while(fast!=NULL && fast->next !=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

node *reverse(node *cur){
    node *prev=NULL;
    while(cur!=NULL){
        node *next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    return prev;
}

int check_palin(){
    node *mid=findmid();
    node *right=mid->next;
    mid->next=NULL;
    right=reverse(right);
    node *left=head;
    while(right){
        if(left->data!=right->data)
        return 0;
        left=left->next;
        right=right->next;
    }
    return 1;
}

void display(){
    node *temp=head;
    while(temp !=NULL){
        printf("%c",temp->data);
    temp=temp->next;
    }
}

int main(){
    char input[100];
    scanf("%[^\n]" ,input);
    printf("\n%s\n",input);
    createnode(input);
    int s=check_palin();
    printf("\n%d\n",s);
    display();
}
