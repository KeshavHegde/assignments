#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char cur[10];
    struct node *next;
}node;

node *head=NULL;
node *top=NULL;

void pop(){
    node *temp=head;
    while(temp->next!=top){
        temp=temp->next;
    }temp->next=NULL;
    top=temp;
}

void createnode(char input[10]){
     if(strcmp(input,"./")==0)
       return;
     else if(strcmp(input,"../")==0){
         pop();
         return;
     }
     node *newnode=(node *)malloc(sizeof(node));
     strcpy(newnode->cur,input);
     newnode->next=NULL;
     if(head==NULL){
         head=newnode;
         top=newnode;
     }else{
         top->next=newnode;
         top=top->next;
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
    display();
        return 0;
}
// {"usr/","./","local/","../","bin/"};
