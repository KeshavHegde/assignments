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
/*
    int main(){
    char input[100];
    fgets(input,sizeof(input),stdin);
    int size=strlen(input);
    if(size>0&&input[size-1]=='\n'){
        input[size-1]='\0';
        size--;
    }
    for(int i=0;i<size;i++){
        if(input[i]=='\"'&&strncmp(&input[i+1],"cd ",3)==0){
            i+=4;
            char word[10];int j=0;
            while(i<size&&input[i]!='\"'){
                word[j++]=input[i++];
            }word[j]='\0';
            createnode(word);
        }
    }
    display();
    return 0;
}
*/

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

