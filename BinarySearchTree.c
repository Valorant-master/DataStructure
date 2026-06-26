#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct BinarySearchTree
{
    int data;
    struct BinarySearchTree* left;
    struct BinarySearchTree* right;
}BST;

//1、根节点为全局变量
// BST* root=NULL;
//GetNewNode
BST* GetNewNode(int data){
    BST* newNode=(BST*)malloc(sizeof(BST));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
//全局变量
// BST* Insert(BST* root,int data){
//     if(root==NULL){
//         root=GetNewNode(data);
//         return root;
//     }
//     else if(data<=root->data){
//         root->left=Insert(root->left,data);
//     }else{
//         root->right=Insert(root->right,data);
//     }
//     return root;
// }
//双重指针
void Insert(BST** rootPtr,int data){
    if(*rootPtr==NULL){
        *rootPtr=GetNewNode(data);
        return;
    }
    // while(*rootPtr!=NULL){
    //    if(data<=(*rootPtr)->data){
    //         rootPtr=&((*rootPtr)->left);
    //    }else if(data>(*rootPtr)->data){
    //         rootPtr=&(*rootPtr)->right;
    //    }
    // }
    // *rootPtr=GetNewNode(data);
    if(data<=(*rootPtr)->data){
        Insert(&((*rootPtr)->left),data);
    }
    else{
        Insert(&((*rootPtr)->right),data);
    }
    //*rootPtr=GetNewNode(data);


}
bool Search(BST* root,int x){
    BST* temp=root;
    //普通版
    while(temp!=NULL){
        if(temp->data==x)
            return true;
        else if(x<temp->data){
            temp=temp->left;
        }else{
            temp=temp->right;
        }
    }
    return false;
    
    //递归版

}
int main(){
    BST* root=NULL;
    BST** rootPtr=&root;
    Insert(rootPtr,1);
    Insert(rootPtr,2);
    Insert(rootPtr,5);
    Insert(rootPtr,3);
    // root=Insert(root,1);
    // root=Insert(root,2);
    // root=Insert(root,5);
    // root=Insert(root,8);
    // root=Insert(root,6);
    if(Search(root,5)){
        printf("find");
    }else{
        printf("wrong");
    }

}