#include<stdio.h>
#include<string.h>

int is_vowel(char  temp_name[]){
    char check=temp_name[0];
    return check=='a'||check=='e'||check=='i'||check=='o'||check=='u'||check=='A'||check=='E'||check=='I'||check=='O'||check=='U';
}

int main(){
    int row,col;
    while (1) {
    printf("Enter number of rows:");
    scanf("%d", &row);
    if (row < 1 || row > 10)
        continue;
    printf("Enter number of columns:");
    scanf("%d", &col);
    if (col < 1 || col > 101)
        continue;
    break;
    }
    char students[row][col][50];
    int vow_count=0;
    char name[50];int max_size=-1;
    printf("Enter the names:");
    for(int itr_row=0;itr_row<row;itr_row++){
        for(int itr_col=0;itr_col<col;itr_col++){
            char temp_name[50];
            printf("Name at (%d,%d):",itr_row,itr_col);
            scanf("%s",temp_name);
            strcpy(students[itr_row][itr_col],temp_name);
            if(is_vowel(temp_name)){
                vow_count++;
            }
            int temp=strlen(temp_name);
            if(temp>max_size){
                max_size=temp;
                strcpy(name,temp_name);
            }
        }
    }

     for(int itr_row=0;itr_row<row;itr_row++){
        for(int itr_col=0;itr_col<col;itr_col++){
            printf("%s\t", students[itr_row][itr_col]);
        }
        printf("\n");
     }
     printf("Number of names starting with a vowel: %d\n",vow_count);
     printf("The longest name: %s",name);
    return 0;
}
