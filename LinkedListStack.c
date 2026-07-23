#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct ListStack{
    int data;
    struct ListStack* next;
}ListStack;

void Init(ListStack** Top){
    (*Top)=NULL;
}

bool ISEmpty(ListStack** Top){
    if((*Top)==NULL){
        return true;
    }else {
        return false;
    }
}

void Push(int x,ListStack** Top){
    ListStack* newNode=(ListStack*)malloc(sizeof(ListStack));
    newNode->next=(*Top);
    newNode->data=x;
    (*Top)=newNode;
}

int Pop(ListStack** Top){
    if((*Top)==NULL){
        return -1;
    }
    int t=(*Top)->data;
    ListStack* temp=(*Top);
    (*Top)=(*Top)->next;
    free(temp);
    temp=NULL;
    return t;
}
int GetTop(ListStack* LST){
    return LST->data;
}

void Traverse(ListStack* LST){
    ListStack* temp=LST;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
}

void DestroyStack(ListStack** Top){
    ListStack* temp=(*Top);
    while((*Top)!=NULL){
        (*Top)=(*Top)->next;
        free(temp);
        temp=(*Top);
    }
    temp=NULL;
}
int main(){
    ListStack* LST;
    ListStack** Top=&LST;
    Init(Top);
    Push(1,Top);
    Push(4,Top);
    Push(3,Top);
    Push(2,Top);
    printf("%d\n",Pop(Top));
    printf("%d\n",GetTop(LST));
    Traverse(LST);
    DestroyStack(Top);
    if(ISEmpty){
        printf("stack is NULL");
    }
}