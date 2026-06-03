#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
    
}Node;
typedef struct LinkedListQueue
{
    struct Node* front;
    struct Node* rear;

}Queue;

void EnQueue(int x,Queue* qu){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=x;
    newNode->next=NULL;
    if(qu->front==NULL&&qu->rear==NULL){
        qu->front=newNode;
        qu->rear=newNode;
        return;
    }
    Node* temp=newNode;
    qu->rear->next=temp;
    qu->rear=temp;
   
}
int DeQueue(Queue* qu){
    if(qu->front==NULL){
        printf("the queue is NULL");
        return -1;
    }
    Node* temp=qu->front;
    int t=temp->data;
    qu->front=qu->front->next;
    free(temp);
    return t;   
}

void Print(Queue* qu){
    Node* temp=qu->front;
    while (temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    
}
int main(){
    Queue q;
    Queue* qu=&q;
    q.front=NULL;
    q.rear=NULL;
    EnQueue(1,qu);
    EnQueue(2,qu);
    EnQueue(3,qu);
    EnQueue(4,qu);
    EnQueue(5,qu);
    DeQueue(qu);
    Print(qu);
    
}