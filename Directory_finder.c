#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Problem: Given a list of file system commands (cd folder/, cd ../, cd ./), determine the current working directory.
 
Example:
Input: ["cd usr/", "cd local/", "cd ../", "cd bin/"]
Output: "/usr/bin/"
*/

typedef struct node{
    char cur[10];
    struct node *next;
}node;

node *head=NULL;

void createnode(char input[10]){
     if(strcmp(input,"./")==0){
            return;
        }
    node *newnode=(node *)malloc(sizeof(node));
    strcpy(newnode->cur,input);
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }else{
        node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }temp->next=newnode;
    }
}

void makeleast(){
    node *curr=head;
    node *prev=NULL;
    while(curr!=NULL && curr->next!=NULL){
    if(strcmp(curr->next->cur,"../")==0){
            if(prev->next!=NULL && curr->next!=NULL){
               prev->next=curr->next->next;
               curr=prev->next;
            }
            else {
                head=curr->next->next;
                curr=head;
               }
               continue;
        }
        prev=curr;
        curr=curr->next;
    }
}

void display(){
    printf("\"/");
    node* temp=head;
    while(temp!=NULL){
        printf("%s",temp->cur);
        temp=temp->next;
    }
    printf("\"");
}
int main(){
    int n;
    printf("Enter the no of commands:");
    scanf("%d",&n);
    for(int i =0; i < n;i++){
        char input[10];
        printf(">");
        scanf(" cd %s",input);
        createnode(input);
    }
    makeleast();
    display();
        return 0;
}
// {"usr/","./","local/","../","bin/"};
