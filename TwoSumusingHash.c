/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 
Constraints:
 
2 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
 
Time constraint : O(n) using hash map*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 1000
typedef struct node{
    int  val;
    int freq;
    int index;
    struct node *next;
}node;

typedef struct hashmap{
    node *hashtable[max];
}hashmap;

int hashkey(int newval){
    return abs(newval) % max;
}
void insertomap(int newval,hashmap *map,int index){
    int key=hashkey(newval);
    node *newnode=(node *)malloc(sizeof(node));
    newnode->val=newval;
    newnode->freq=1;
    newnode->index=index;
    newnode->next=map->hashtable[key];
    map->hashtable[key]=newnode;
}

int search(hashmap *map,int val){
    int key= hashkey(val);
    node *temp=map->hashtable[key];
    while(temp!=NULL ){
        if (temp->val == val) 
            return temp->index;
        temp=temp->next;
    }
    return -1;
}

int main(){
    int *input=NULL;int size=0;
    char data[10000];
    scanf("[ %[^]] ]",data);
    long target;int index1=0,index2=-1;
    scanf("%ld",&target);
    hashmap *map=(hashmap*)malloc(sizeof(hashmap));
    memset(map->hashtable, 0, sizeof(map->hashtable));
    char *ptr=strtok(data, ",");
    while(ptr){
        input=(int *)realloc(input,(size+1)*sizeof(int));
        int newval=atoi(ptr);
        insertomap(newval,map,index1);
        int remaining=target-newval;
        index2=search(map,remaining);
        if(index2!=-1){
            printf("[%d,%d]",index2,index1);
            return 0;
        }
        index1++;
        ptr=strtok(NULL,",");
        size++;
    }
    if(index2==-1){
        printf("no target");
    }
    return 0;
}
