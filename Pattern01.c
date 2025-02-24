// 1 2 3 4 5 4 3 2 1 
// 1 2 3 4 - 4 3 2 1 
// 1 2 3 - - - 3 2 1 
// 1 2 - - - - - 2 1 
// 1 - - - - - - - 1

#include <stdio.h>

void incrementer(int k ,int i,int j){
    if(i>(k-j))
    return ;
    printf("%d ",i);
    incrementer(k,i+1,j);
}

void spacegiver(int k,int i,int j){
    if(i>(j*2)-2 ||j>=k)
    return ;
    printf("- ");
    return spacegiver(k,i+1,j);
    
}
void decrementer(int k ,int i,int j){
    if(i>(k-j))
    return ;
    decrementer(k,i+1,j);
    if(i!=k)
    printf("%d ",i);
}

void displayer(int k ,int i,int j){
    if(j==-1)
    return ;
    displayer(k,i,j-1);
    incrementer(k,i,j);
    spacegiver(k,0,j);
    decrementer(k,i,j);
    printf("\n");
}
int main() {
    int k;
    scanf("%d",&k);
    displayer(k,1,k);

    return 0;
}
