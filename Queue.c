#include<stdio.h> 
#define Max 5
typedef struct Queue
{
    int data[Max];
    int front;
    int rear;
}Queue;
// normal queue
// void EnQueue(int x,Queue* q){
//     if(q->front==-1){
//         q->front++;
//     }
//     if(q->rear+1==Max){
//         printf("the queue is full\n");
//     }else{
//         q->rear++;
//         q->data[q->rear]=x;
//     }
    
// }

// int DeQueue(Queue* q){
//     if(q->front==Max){
//         printf("the queue is empty\n");
//         return -1;
//     }
//     int t=q->data[q->front];
//     q->front++;
//     return t;
// }

// void Print(Queue q){
//     for(int i=q.front;i<=q.rear;i++){
//         printf("%d\n",q.data[i]);
//     }
// }


// loop queue
//弊端：留一个空位来判断队列是满还是空，所以队首和队尾从0开始，不是-1
//解决方法：
//1、新增属性size记录队列中元素个数，每次入队出队进行对应的加减操作
//2、用一个bool变量(tag)来记录，每次入队成功，tag=true;出队成功，tag=false;
//当 front == rear 时：如果 tag == false，说明刚进行了出队导致相等，队列为空；如果 tag == true，说明刚进行了入队导致相等，队列为满
void EnQueue(int x,Queue* q){
    //判断队列是否已满
    if((q->rear+1)%Max==q->front){
        printf("the queue is full\n");
        return;
    }
    // //第一个元素入队，队首队尾同时加1
    // if(q->front==q->rear&&q->front==-1){
    //     q->front++;
    // }
    q->data[q->rear]=x;
    q->rear=(q->rear+1)%Max;
}

int DeQueue(Queue* q){
    //判空
    if(q->front==q->rear){
        printf("the queue is empty");
        return -1;
    }
    int t=q->data[q->front];
    q->front=(q->front+1)%Max;
    return t;
}
void Print(Queue* q){
    if (q->front == q->rear) {
        printf("队列为空\n");
        return;
    }
    int i = q->front;
    while (i != q->rear) {
        printf("%d\n", q->data[i]);
        i = (i + 1) % Max;
    }
}

int main(){
    Queue qu;
    qu.front=0;
    qu.rear=0;
    Queue* q=&qu;
    // normal queue test
    // EnQueue(1,q);
    // EnQueue(2,q);
    // EnQueue(3,q);
    // EnQueue(4,q);
    // EnQueue(5,q);    
    // EnQueue(6,q);
    // DeQueue(q);
    // Print(qu);


    EnQueue(1,q);
    EnQueue(2,q);
    EnQueue(3,q);
    EnQueue(4,q);
    EnQueue(5,q);
    EnQueue(6,q);
    int t=DeQueue(q);
    printf("%d\n",t);

    Print(q);



}