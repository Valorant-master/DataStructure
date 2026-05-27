#include<stdio.h>
#include<stdbool.h>
#define MAX 100
typedef struct {
    int data[MAX];
    int top;
}Stack;
void initStack(Stack *s){
    s->top=-1;
}
void push(Stack* s,int x){
    if(s->top==MAX-1){
        printf("Stack overflow\n");
        return;    
    }
    s->top++;
    s->data[s->top]=x;
}
int pop(Stack* s){
    if(s->top==-1){
        printf("No elements to pop\n");
        return -1;
    }
    int t=s->data[s->top];
    s->top--;
    return t;
}
int top(Stack* s){
    if(s->top==-1){
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top];
}
bool isEmpty(Stack* s){
    if(s->top==-1){
        return true;
    }else{
        return false;
    }

}
void display(Stack* s){
    if(s->top==-1){
        printf("Stack is empty\n");
        return;
    }
    for(int i=s->top;i>=0;i--){
        printf("%d ",s->data[i]);
    }
    printf("\n");
}
int main(){
    Stack s;
    initStack(&s);
    push(&s,10);
    push(&s,9);
    push(&s,8);
    push(&s,7);
    push(&s,6);
    push(&s,5);
    pop(&s);
    display(&s);
    if(isEmpty(&s)){
        printf("Stack is empty\n");
    }
    printf("Top element is %d\n",top(&s));
    return 0;
}