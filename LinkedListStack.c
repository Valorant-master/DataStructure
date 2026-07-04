#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}StackNode;
// //double pointer example
// // void ReverseStack(StackNode** top){
// //     StackNode* prev=NULL;
// //     StackNode* current=*top;
// //     StackNode* next=NULL;
// //     while(current!=NULL){
// //         next=current->next;
// //         current->next=prev;
// //         prev=current;
// //         current=next;
// //     }
// //     *top=prev;
// // }
// //需要重写
// typedef struct addressStack{
//     StackNode* top;
//     struct addressStack* next;
// }addressStack;

// void addressPush(addressStack** ads,StackNode* top){
//     StackNode* temp=top;
//     while(temp!=NULL){
//         addressStack* newNode=(addressStack*)malloc(sizeof(addressStack));
//         newNode->top=temp;
//         newNode->next=*ads;
//         *ads=newNode;
//         temp=temp->next;
//     }
// }

// void addressPop(addressStack** ads,StackNode** t){
//     addressStack* temp=*ads;
//     *t=temp->top;
//     *ads=(*ads)->next;
//     free(temp);
//     StackNode* currNode=*t;
//     while(*ads!=NULL){
//         addressStack* nextAddr=*ads;
//         currNode->next=nextAddr->top;
//         currNode=currNode->next;
//         *ads=(*ads)->next;
//         free(nextAddr);
        
        
//     }
    
//     currNode->next=NULL;
// }
 



// void push(StackNode** t ,int x){
//     StackNode* newNode=(StackNode*)malloc(sizeof(StackNode));
//     newNode->data=x;
//     newNode->next=*t;
//     *t=newNode;
// }


// int pop(StackNode** t){
//     if(*t==NULL){
//         printf("Stack is empty\n");
//         return -1;
//     }
//     StackNode* temp=*t;
//     int data=temp->data;
//     *t=(*t)->next;
//     free(temp);

// }
// int top(StackNode* top){
//     if(top==NULL){
//         printf("Stack is empty\n");
//         return -1;
//     }
//     return top->data;
// }

// void display(StackNode* top){
//     if(top==NULL){
//         printf("Stack is empty\n");
//         return;
//     }
//     StackNode* temp=top;
//     while(temp!=NULL){
//         printf("%d ",temp->data);
//         temp=temp->next;
//     }
//     printf("\n");
// }

// int main(){

//     StackNode* top=NULL;
//     StackNode** t=&top;
//     addressStack* addresstop=NULL;
//     addressStack** ads=&addresstop;
//     push(t,10);
//     push(t,9);
//     push(t,8);
//     push(t,7);
//     pop(t);
//     push(t,6);
//     display(top);
//     addressPush(ads,top);
//     addressPop(ads,t);
//     //Reverse(an,t);
//     display(top);
// }

// //double pointer example
// // int a=9;
//     // int* p=&a;
//     // int** pp=&p;
//     // printf("%p\n",a);
//     // printf("%p\n",*p);
//     // printf("%p\n",**pp);