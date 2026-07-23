#include<stdio.h>
#include<stdlib.h>
#define Max 10
typedef struct Stack{
    int data[Max];
    int top;
}Stack;

Stack* Inint(){
    Stack* ST=(Stack*)malloc(sizeof(Stack));
    ST->top=-1;
    return ST;
}
void Push(int x,Stack** S){
    if((*S)->top==Max-1){
        printf("full");
        return ;
    }
    (*S)->top++;
    (*S)->data[(*S)->top]=x;
}
int Pop(Stack** S){
    if((*S)->top==-1){
        printf("Stack is empty");
        return -1;
    }
    int t=(*S)->data[(*S)->top];
    (*S)->top--;
    return t;
}

int Peek(Stack** S){
    if((*S)->top==-1){
        printf("Stack is empty");
        return -1;
    }
    return (*S)->data[(*S)->top];
}
int main(){
    Stack* ST=Inint();
    Stack** S=&ST;
    Push(1,S);
    Push(9,S);
    Push(6,S);
    Push(5,S);
    Push(8,S);
    Pop(S);
    Pop(S);
    //Pop(S);

    printf("%d\n",Peek(S));
}