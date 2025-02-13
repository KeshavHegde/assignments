/*Problem Statement: Given a circular integer array A, return the next greater element for every element in A. The next greater element for an element x is the first element greater than x that we come across while traversing the array in a clockwise manner. If it doesn't exist, return -1 for this element.*/
//size=11, A[] = {3,10,4,2,1,2,6,1,7,2,9}
//res={10,-1,6,6,2,6,7,7,9,9,10}
#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int *arr;
    int top;
}stack;

void push(stack *st,int val){
    st->arr[++(st->top)]=val;
}

void pop(stack *st){
    if(st->top!=-1)
        (st->top)--;
}

int top(stack *st){
    if(st->top!=-1)
        return st->arr[st->top];
    return -1;
}

void generateelement(int *input,int size){
    stack *st=(stack*)malloc(sizeof(stack));
    st->arr=(int*)malloc(size*sizeof(int));
    st->top=-1;
    int res[size];
    for(int i=0;i<size;i++)
        res[i]=-1;
    int itr=2;
    while(itr--){
        for(int current=size-1;current>=0;current--){
            while(st->top!=-1 && input[current]>=top(st))
                pop(st);
            if(st->top!=-1)
                res[current]=top(st);
            push(st,input[current]);
        }
    }
    for(int i=0;i<size;i++){
        printf("%d",res[i]);
        if(i!=size-1)
            printf(",");
    }
    printf("\n");
    free(st->arr);
}

int main(){
    int size;
    scanf("%d",&size);
    int *inputArray=(int*)malloc(size*sizeof(int));
    for(int i=0;i<size;i++)
        scanf("%d",&inputArray[i]);
    generateelement(inputArray,size);
    free(inputArray);
    return 0;
}
