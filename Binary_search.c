// create a linked list from a given array of rollno. and name  and search the rollnum  and print the name of the student 
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct student{
    char name[10];
    int rollno;
    struct  student *next;
}stud;

stud *head=NULL;

void createnode(char name[10],int rollno){
    stud* newnode=(stud*)malloc(sizeof(stud));
    strcpy(newnode->name,name);
    newnode->rollno=rollno;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        return ;
    }
    stud* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
} 

stud* findmid(stud *start,stud *end ){
    if(start==NULL)
    return NULL;
    stud *slow=start;
    stud *fast=start->next;
    while(fast!=end ){
        fast=fast->next;
        if(fast!=end){
        slow=slow->next;
        fast=fast->next;
        }
    }
    return slow;
}
void binary_search(stud* start,stud* end,int rollno){
    if(start==NULL || start==end)
     return ;
        stud* middle=findmid(start,end);
        if(middle->rollno==rollno){
            printf("\nRoll no %d is %s",rollno,middle->name);
            return ;
        }if(middle->rollno >rollno){
             end=middle;
             binary_search(start,end,rollno);
        }else{
             start=middle->next;
             binary_search(start,end,rollno);
        }
}

void display(){
    stud* temp=head;
    while(temp!=NULL){
        printf("Roll no:%d name:%s\n",temp->rollno,temp->name);
        temp=temp->next;
    }
}

int main(){
    int input_array[]={1,2,3,4,5,6,7,8,9,10};
    int size=10;
    char names[10][10] = {"ram", "sham", "bham", "om", "nom","vivek","ankit","chandan","riya","dhanush"};
    for(int itr=0;itr<size;itr++){
        createnode(names[itr],input_array[itr]);
    }
    printf("student list:\n");
    display();
    int search=8;
    binary_search(head,NULL,search);
    return 0;
}
