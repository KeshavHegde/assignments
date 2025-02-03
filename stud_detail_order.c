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

void sorting(int size){
    stud * temp=head;
    int i=0;
    while(i<size-1){
        int j=0;
        stud *temp=head;
        while(j<size-i-1){
            if(temp->marks<=temp->next->marks){
                if(temp->marks ==temp->next->marks){
                    if(temp->usn>temp->next->usn){
                        int tempi=temp->marks;
                        temp->marks=temp->next->marks;
                        temp->next->marks=tempi;
                        int tempj=temp->usn;
                        temp->usn=temp->next->usn;
                        temp->next->usn=tempj;
                        char tempn[10];
                        strcpy(tempn,temp->name);
                        strcpy(temp->name,temp->next->name);
                        strcpy(temp->next->name,tempn);
                    }
                }else{
                int tempi=temp->marks;
                temp->marks=temp->next->marks;
                temp->next->marks=tempi;
                int tempj=temp->usn;
                temp->usn=temp->next->usn;
                temp->next->usn=tempj;
                char tempn[10];
                strcpy(tempn,temp->name);
                strcpy(temp->name,temp->next->name);
                strcpy(temp->next->name,tempn);
                }
            }
            temp=temp->next;
            j++;
        }
        i++;
    }
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
    scanf("%d",&input_num);int i=0;
    int size=input_num;
    printf("enter details:\n");
    while(i!=input_num){
        char name[10];
        int marks,usn;
        scanf("%s %d %d",name,&marks,&usn);
        createnode(name,marks,usn);
        i++;
    }
    sorting(size);
    display();
}
