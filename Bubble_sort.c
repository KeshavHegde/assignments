// convert a given list of roll numbers and names into a linked list and then sort that list based on the roll numbers of the students.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
    char name[10];
    int rollno;
    struct student *next;
}stud;

stud *head=NULL;

void createnode(char name[10],int rollno){
    stud *newnode=(stud*)malloc(sizeof(stud));
    strcpy(newnode->name,name);
    newnode->rollno=rollno;
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

int list_length(){
    int length=0;
    stud *current=head;
    while(current!=NULL){
        length++;
        current=current->next;
    }
    return length;
}

void bubble_sort(){
    int len=list_length();
    int count=0;
    while(count<len-1){
        stud *temp=head;
        int inner_count=0;
        while(inner_count<len-count-1){
            if(temp->rollno>temp->next->rollno){
                char t_name[10];
                strcpy(t_name,temp->name);
                strcpy(temp->name,temp->next->name);
                strcpy(temp->next->name,t_name);
                int t_rollno=temp->rollno;
                temp->rollno=temp->next->rollno;
                temp->next->rollno=t_rollno;
            }
            temp=temp->next;
            inner_count++;
        }
        count++;
    }
}

void display(){
    stud *temp=head;
    while(temp!=NULL){
        printf("Roll no:%d, Name:%s\n",temp->rollno,temp->name);
        temp=temp->next;
    }
}

int main(){
    int rollnos[]={1,3,9,2,8,4,7,5,6,10};
    int size=10;
    char names[10][10]={"ram","sham","bham","om","nom","vivek","ankit","chandan","riya","dhanush"};
    for(int itr=0;itr<size;itr++){
        createnode(names[itr],rollnos[itr]);
    }
    printf("Before sorting the student list:\n");
    display();
    bubble_sort();
    printf("\nAfter sorting the student list:\n");
    display();
    return 0;
}
