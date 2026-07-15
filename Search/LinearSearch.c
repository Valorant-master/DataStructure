#include<stdio.h>
#include<stdlib.h>
#define Max 10
typedef struct SearchTable
{
    int data[Max];
    int length;
}SearchTable;

SearchTable* InitTable(){
    SearchTable* ST=(SearchTable*)malloc(sizeof(SearchTable));
    for(int i=0;i<10;i++){
        ST->data[i]=i*3;
    }
    ST->length=Max;
    return ST;
}

int Search(SearchTable* ST,int x){
    int i=ST->length-1;
    while(i>=0){
        if(ST->data[i]==x){
            return i;
        }
        else{
            i--;
        }
    }
    return -1;
}

int main(){
    SearchTable* ST=NULL;
    ST=InitTable();
    printf("%d",Search(ST,9));
    free(ST);
    ST=NULL;
}