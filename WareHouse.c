#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Warehouse Inventory Tracking System You are building a warehouse inventory system to track item quantities. 
The system supports adding items, updating quantities, and querying the quantity of a specific item.
• "ADD " → Adds a new item with the given quantity. If the item already exists, increase its quantity.
• "UPDATE " → Updates the quantity of an existing item to the new quantity. 
• "QUERY " → Returns the current quantity of the specified item. If the item does not exist, return "Item not found".
 Input: The first line contains an integer n (1 ≤ n ≤ 100) — the number of commands. 
 The next n lines contain a command of one of the following types:
• "ADD " • "UPDATE " • "QUERY " Output: For each "QUERY" command,
print the current quantity of the item or "Item not found"
*/

typedef struct node{
    char item[100];
    int quantity;
    struct node * next;
}node;

typedef struct hashmap{
    node *hashtable[10];
}hashmap;

int mapkey(char *item){
    unsigned int key=5461;
    char *ptr=item;
    while(*ptr++){
        key=((key<<5)+key)+*ptr;
    }
    return key%10;
}

void insert(hashmap *map,char *item,int quantity){
    int key=mapkey(item);
    node *temp=map->hashtable[key];
    while(temp!=NULL){
        if(strcmp(temp->item,item)==0){
            temp->quantity+=quantity;
            return ;
        }
        temp=temp->next;
    }
    node *newnode=(node *)malloc(sizeof(node));
    strcpy(newnode->item,item);
    newnode->quantity=quantity;
    newnode->next=map->hashtable[key];
    map->hashtable[key]=newnode;
}

void update(hashmap *map,char *item,int quantity){
    int key=mapkey(item);
    node *temp=map->hashtable[key];
    while(temp!=NULL){
        if(strcmp(temp->item,item)==0){
            temp->quantity=quantity;
            return ;
        }
        temp=temp->next;
    }
}

int search(hashmap *map,char *item){
    int key=mapkey(item);
    node *temp=map->hashtable[key];
    while(temp!=NULL){
        if(strcmp(temp->item,item)==0){
            return temp->quantity;
        }
        temp=temp->next;
    }
    return -1;
}

int main(){
    int num;
    scanf("%d",&num);
    hashmap *map=(hashmap *)malloc(sizeof(hashmap));
     for (int i = 0; i < 10; i++) {
        map->hashtable[i] = NULL;
    }
    for(int i=0;i<num;i++){
        char command[200];
        getchar();
        scanf("%[^\n]",command);
        char item[100];
        int quantity;
        if(sscanf(command,"ADD %s %d",item,&quantity)==2){
            insert(map,item,quantity);
        }else if(sscanf(command,"UPDATE %s %d",item,&quantity)==2){
            update(map,item,quantity);
        }
        else if(sscanf(command,"QUERY %s ",item)==1){
            int size=search(map,item);
            if(size==-1){
                printf("not found");
            }else{
                printf("%s : %d",item,size);
            }
        } else {
            printf("Invalid command\n");
        }
    }
}
