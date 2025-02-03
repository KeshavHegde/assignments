#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stud{
    char name[10];
    int marks;
    int usn;
    struct stud *next;
}stud;

stud *head=NULL;

void createnode(char name[10],int marks,int usn){
    stud *newl=(stud *)malloc(sizeof(stud));
    strcpy(newl->name,name);
    newl->marks=marks;
    newl->usn=usn;
    newl->next=NULL;
    if(head==NULL){
        head=newl;
        return ;
    }
    stud *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }temp->next=newl;
}

stud* findmid(stud *head){
    stud* slow=head;
    stud* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

stud* merge(stud* left, stud* right){
    stud* newhead=NULL,*temp=NULL;
    while(left!=NULL && right!=NULL){
        stud *maxnode;
        if (left->marks<right->marks) {
            maxnode=right;
            right=right->next;
        } else if (left->marks > right->marks) {
            maxnode=left;
            left=left->next;
        } else { 
            if (left->usn<right->usn) {
                maxnode=right;
                right=right->next;
            } else {
                maxnode=left;
                left=left->next;
            }
        if(newhead==NULL){
            newhead=maxnode;
            temp=maxnode;
        }else{
            temp->next=maxnode;
            temp=temp->next;
        }
        if(left != NULL) {
            temp->next=left;
        }else{
            temp->next=right;
         }
    }
    return newhead;
}

stud * sorting(stud *left){
    if(left==NULL || left->next==NULL)
      return left;
    stud* mid=findmid(left);
    stud *right=mid->next;
    mid->next=NULL;
    left=sorting(left);
    right=sorting(right);
    return merge(left,right);
}

void display(){
    stud *temp=head;
    while(temp!=NULL){
        printf("%s %d %d\n",temp->name,temp->marks,temp->usn);
        temp=temp->next;
    }
}

int main(){
    int input_num;
    scanf("%d",&input_num);
    int i=0;
    int size=input_num;
    printf("enter details:\n");
    while(i!=input_num){
        char name[10];
        int marks,usn;
        scanf("%s %d %d",name,&marks,&usn);
        createnode(name,marks,usn);
        i++;
    }
    head=sorting(head);
    display();
}
