#include<stdio.h>
#include<stdlib.h>
#define Max 10
typedef struct SearchTable
{
    int data[Max];
    int length;
}SearchTable;

SearchTable* Init(){
    SearchTable* ST=(SearchTable*)malloc(sizeof(SearchTable));
    for(int i=0;i<Max;i++){
        ST->data[i]=i*7;
    }
    ST->length=Max;
    return ST;
}
int BinarySearch(SearchTable* ST,int x){
    int low=0,high=Max-1,mid=(low+high)/2;
    while(ST->data[mid]>x&&high>low){
        high=mid-1;
        mid=(low+high)/2;
    }
    while(ST->data[mid]<x&&high>low){
        low=mid+1;
        mid=(low+high)/2;
    }
    if(ST->data[mid]==x){
        return mid;
    }else{
        return -1;
    }

}
int main(){
    SearchTable* ST=Init();
    printf("%d",BinarySearch(ST,22));
    free(ST);
    ST=NULL;
}