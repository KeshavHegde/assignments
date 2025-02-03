// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct words{
    int num;
    char word[10];
    struct words *next;
}words;

words *head=NULL;

int isdigi(char num){
    return num>='0' && num<='9';
}

void inserttonode(int num,char word[]){
    words *newnode=(words *)malloc(sizeof(words));
    newnode->num=num;
    strcpy(newnode->word,word);
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        return;
    }
    words *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}

void display(){
    words *temp=head;
    while(temp!=NULL){
        for(int i=temp->num;i>0;i--){
            printf("%s",temp->word);
        }
        temp=temp->next;
    }
}
words* findmid(words *left){
    words *slow=left;
    words *fast=left->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
words *merge(words *left,words *right){
    words *newhead=NULL,*temp;
    while(left!=NULL&& right!=NULL){
        words *minnode;
        if(strcmp(left->word,right->word)<0){
            minnode=left;
            left=left->next;
        }else{
            minnode=right;
            right=right->next;
        }
        if(newhead==NULL){
            newhead=minnode;
            temp=minnode;
        }else{
            temp->next=minnode;
            temp=temp->next;
        }
    }
    if(left!=NULL){
        temp->next=left;
    }else{
        temp->next=right;
    }
    return newhead;
}

words *divide(words *left){
    if(left==NULL || left->next==NULL)
     return left;
    words *mid=findmid(left);
    words *right=mid->next;
    mid->next=NULL;
    left=divide(left);
    right=divide(right);
    return merge(left,right);
    
}

int main() {
    char input[100];
    fgets(input,sizeof(input),stdin);
    int size=strlen(input);
    if(size>0 && input[size-1]=='\n'){
        input[size-1]='\0';
        size--;
    }
    for(int i=0;i<size;){
        int num=0;char word[10];
        while(isdigi(input[i])){
            num=(num*10)+(input[i]-'0');
            i++;
        }int j=0;
        if(input[i]=='['){
            i++;
            while(input[i]!=']'){
            word[j]=input[i];
            i++;j++;
            }word[j]='\0';
        }
        inserttonode(num,word);
        i++;
    }
    printf("Before sorting:\n");
    display();
    head=divide(head);
    printf("\nAfetr sorting:\n");
    display();
    return 0;
}
