#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct stack{
    char data;
    struct stack* next;
}ParenthesStack;

void push(char* ch,ParenthesStack** top){
        ParenthesStack* newNode=(ParenthesStack*)malloc(sizeof(ParenthesStack));
        newNode->data=*ch;
        newNode->next=*top;
        *top=newNode;
    
}
bool pop(char* ch,ParenthesStack** top){
    if((*top)==NULL){
        return false;
    }
   char t=(*top)->data;
   if(*ch==')'&&t=='('||*ch=='}'&&t=='{'||*ch==']'&&t=='['){
    ParenthesStack* temp=*top;
    (*top)=(*top)->next;
    free(temp);
    return true;
   }
   else return false;
}
bool isBalanced(char* ch,ParenthesStack**top){
    while(*ch!='\0'){
        if(*ch=='(' || *ch == '[' || *ch == '{'){
            push(ch,top);
        }
        if(*ch==')' || *ch == ']' || *ch == '}'){
            if(!pop(ch,top)){
                return false;
            }
        }
        ch++;
    }
    if((*top)!=NULL){
        return false;
    }
    else    return true;
}

int main(){
    ParenthesStack* ps=NULL;
    ParenthesStack** top=&ps;
    char ch[]={'{','[',']','}'};
    if(isBalanced(ch,top)){
        printf("is balanced");
    }else{
        printf("not balanced");
    }
    
    return 0;

}