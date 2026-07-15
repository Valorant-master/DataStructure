#include<stdio.h>
#define max 10
int* Init(){
    int* HashTable=(int*)malloc(sizeof(max));
    for(int i=0;i<max;i++){
        HashTable[i]=-1;
    }
    return HashTable;
}
HashFunction(int x,int*  HashTable){
    int i=x%13;
    if(HashTable[i]!=-1){
        HashTable[i]=x;
    }else{
        
    }
}

int main(){
    int* HashTable=Init;
}