#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int roomno;
    int status;
    struct node * next;
}node;

typedef struct hashmap{
    node *hashtable[10];
}hashmap;

int mapkey(int k){
    return (k-1)%10;
}

void turnon(hashmap *map,int roomno){
    int key=mapkey(roomno);
    node *temp=map->hashtable[key];
    while(temp!=NULL){
        if(temp->roomno==roomno){
            temp->status=1;
            return ;
        }
        temp=temp->next;
    }
}
void turnoff(hashmap *map,int roomno){
    int key=mapkey(roomno);
    node *temp=map->hashtable[key];
    while(temp!=NULL){
        if(temp->roomno==roomno){
            temp->status=0;
            return ;
        }
        temp=temp->next;
    }
}

int findstatus(hashmap *map,int roomno){
    int key=mapkey(roomno);
    node *temp=map->hashtable[key];
    while(temp!=NULL){
        if(temp->roomno==roomno){
             return temp->status;
        }
        temp=temp->next;
    }
}

int main(){
    int num;
    scanf("%d",&num);
    hashmap *map=(hashmap *)malloc(sizeof(hashmap));
     for (int i = 0; i < 10; i++) {
        map->hashtable[i] = NULL;
    }
    for (int i = 0; i < 10; i++) {
        node *newnode=(node *)malloc(sizeof(node));
        newnode->roomno=i+1;
        newnode->status=0;
        newnode->next=map->hashtable[i];
        map->hashtable[i]=newnode;
    }
    for(int i=0;i<num;i++){
        char command[200];
        getchar();
        scanf("%[^\n]",command);
        int roomno;
        if(sscanf(command,"TURN_ON <%d>",&roomno)==1){
            turnon(map,roomno);
        }else if(sscanf(command,"TURN_OFF <%d>",&roomno)==1){
            turnoff(map,roomno);
        }
        else if(sscanf(command,"STATUS <%d>",&roomno)==1){
            int state=findstatus(map,roomno);
            if(state==0){
                printf("OFF \n");
            }else{
                printf("ON \n");
            }
        } else {
            printf("Invalid command\n");
        }
    }
    return 0;
}
