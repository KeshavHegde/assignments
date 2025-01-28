// convert a given list of names into a linked list and then sort that list based on the names of the students and assign the roll number to each.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
    char name[20];
    int rollno;
    struct student *next;
}stud;

stud *head=NULL;

void createnode(char name[20]){
    stud *newnode=(stud *)malloc(sizeof(stud));
    strcpy(newnode->name,name);
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        return;
    }
    stud *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}

void display(){
    stud *temp=head;
    while(temp!=NULL){
        printf("Name: %s ,Roll no: %d\n",temp->name,temp->rollno);
        temp=temp->next;
    }
}

void selection_sort(){
    stud *temp1=head;
    int rollno=1;
    while(temp1!=NULL){
        stud *minnode=temp1;
        stud *temp2=temp1->next;
        while(temp2!=NULL){
            if(strcmp(temp2->name,minnode->name)<0){
                minnode=temp2;
            }
            temp2=temp2->next;
        }
        if(minnode!=temp1){
            char temp_name[20];
            strcpy(temp_name,temp1->name);
            strcpy(temp1->name,minnode->name);
            strcpy(minnode->name,temp_name);
        }
        temp1->rollno=rollno++;
        temp1=temp1->next;
    }
}

int main(){
    char names[10][20]={"ram","sham","bham","om","nom","vivek","ankit","chandan","riya","dhanush"};
    int size=10;
    for(int i=0;i<size;i++){
        createnode(names[i]);
    }
    printf("Before sorting the student list:\n");
    display();
    selection_sort();
    printf("\nAfter sorting the student list:\n");
    display();
    return 0;
}
