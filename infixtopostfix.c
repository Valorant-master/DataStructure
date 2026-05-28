#include<stdio.h>
#include<stdlib.h>
typedef struct operatorStack
{
    char data;
    struct operatorStack* next;
}operatorStack;

typedef struct operandStack
{
    int data;
    struct operandStack* next;
}operandStack;



void push(char s,operatorStack** top){
    operatorStack* newNode=(operatorStack*)malloc(sizeof(operatorStack));
    newNode->data=s;
    newNode->next=*top;
    (*top)=newNode;
}
char pop(operatorStack** top){
    if((*top)==NULL){
        printf("stack is empty");
        return -1;
    }
    operatorStack* temp=*top;
    char x=temp->data;
    (*top)=(*top)->next;
    free(temp);
    return x;    
}
void parenthesesPush(char* s,operatorStack** top){
    //char *temp=s;
    while(*s!='\0'){
        if(*s=='{'||*s=='['||*s=='('){
            push(*s,top);
        }
        s++;
    }
    while((*top)!=NULL){
       char temp= pop(top);
       printf("%c",temp);
    }
    
    
}

int main(){
    operatorStack* ops=NULL;
    operatorStack** top=&ops;
    //char ch[6]={'1','{','[','(','2'};
    //Check whether parentheses can be pushed onto the stack
    // char ch[10];
    // printf("input your string");
    // scanf("%s",&ch);
    // char* s=ch;
    // parenthesesPush(s,top);
    
}
