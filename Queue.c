#include<stdio.h> 
#define Max 5
typedef struct Queue
{
    int data[Max];
    int front;
    int rear;
}Queue;

void EnQueue(int x,Queue* q){
    if(q->rear==q->front&&q->front==-1){
        q->front++;
    }
    q->data[++(q->rear)]=x;
}
int DeQueue(Queue* q){
    if(q->rear!=-1){
        int t=q->data[(q->rear)--];
    return t;
    }else{
        printf("queue is empty");
        return -1;
    } 
}

// // loop queue
// void EnQueue(int x,Queue* q){
//     if(q->front==q->rear&&q->front!=-1){
//         printf()
//     }
// }
void PrintQueue(Queue q){
    int t=q.rear;
    for(int i=0;i<=t;i++){
        printf("%d\n",q.data[i]);
    }

}
int main(){
    Queue qu;
    qu.front=-1;
    qu.rear=-1;
    Queue* q=&qu;
    EnQueue(1,q);
    EnQueue(2,q);
    EnQueue(3,q);
    EnQueue(4,q);
    DeQueue(q);
    PrintQueue(qu);
    
}