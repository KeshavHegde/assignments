#include <stdio.h>
#include <stdlib.h>

#define size 10

typedef struct node{
    int k,v;
    struct node*next;
}node;

node*table[size]={NULL};

int hash(int k){
    return k%size;
}

node*newnode(int k,int v){
    node*n=(node*)malloc(sizeof(node));
    n->k=k;
    n->v=v;
    n->next=NULL;
    return n;
}

void insert(int k,int v){
    int i=hash(k);
    node*n=newnode(k,v);
    node*t=table[i];
    while(t){
        if(t->k==k){
            t->v=v;
            free(n);
            return;
        }
        t=t->next;
    }
    n->next=table[i];
    table[i]=n;
}

int search(int k){
    int i=hash(k);
    node*t=table[i];
    while(t){
        if(t->k==k)return t->v;
        t=t->next;
    }
    return-1;
}

void del(int k){
    int i=hash(k);
    node*t=table[i],*p=NULL;
    while(t){
        if(t->k==k){
            if(p)p->next=t->next;
            else table[i]=t->next;
            free(t);
            printf("Key %d deleted.\n",k);
            return;
        }
        p=t;
        t=t->next;
    }
    printf("Key %d not found.\n",k);
}

void display(){
    printf("Hash Table:\n");
    for(int i=0;i<size;i++){
        int flag=0;
        if(table[i]!=NULL){
        printf("Index %d: ",i);
        node*t=table[i];
        while(t){
            if(flag==1){
                printf(" -> ");
            }
            printf("(%d,%d)",t->k,t->v);
            t=t->next;
            flag=1;
        }
        printf("\n");
        }
    }
}

int main(){
    int c,k,v;
    while(1){
        printf("\n1.Insert 2.Search 3.Delete 4.Display 5.Exit\n");
        scanf("%d",&c);
        switch(c){
            case 1:
                printf("Enter the Key: ");
                scanf("%d",&k);
                printf("Value: ");
                scanf("%d",&v);
                insert(k,v);
                break;
            case 2:
                printf("Enter the Key: ");
                scanf("%d",&k);
                v=search(k);
                if(v!=-1)printf("Value : %d\n",v);
                else printf("Key not found.\n");
                break;
            case 3:
                printf("Enter the Key: ");
                scanf("%d",&k);
                del(k);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
