#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

typedef struct BinarySearchTree
{
    int data;
    struct BinarySearchTree* left;
    struct BinarySearchTree* right;
}BST;

typedef struct QueueNode
{   
    BST* treeNode;
    struct QueueNode* next;
}QueueNode;

typedef struct Queue{
    QueueNode* front;
    QueueNode* rear;
}Queue;

void InitQueue(Queue* q){
    q->front=NULL;
    q->rear=NULL;
}

bool IsEmpty(Queue* q){
    // if(q->front==NULL){
    //     return true;
    // }else{
    //     return false;
    // }
    return q->front==NULL;
}
void EnQueue(BST* treeNode,Queue* q){
    QueueNode* newNode=(QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode=treeNode;
    newNode->next=NULL;
    if(IsEmpty(q)){
        q->front=newNode;
        q->rear=newNode;
    }else{
        q->rear->next=newNode;
        q->rear=newNode;
    }
}

BST* DeQueue(Queue* q){
     if (IsEmpty(q))
        return NULL;

    QueueNode* temp = q->front; // 暂存队头
    BST* res = temp->treeNode; // 取出树节点
    q->front = q->front->next; // 队头后移
    free(temp); // 释放旧队列节点

    // 如果队头变空，同步置尾为空
    if (q->front == NULL)
        q->rear = NULL;

    return res;
}




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
int FindMin(BST* root){
    if(root==NULL){
        printf("tree is empty");
        return -1;
    }
    //普通版
    // else if(root->left==NULL){
    //     return root->data;
    // }else
    // {
    //     while (root->left!=NULL)
    //     {
    //         root=root->left;
    //     }
    //     return root->data;
    // }
    //递归实现
    else{
        if(root->left==NULL){
            return root->data;
        }
    }
    return FindMin(root->left);
}

int FindMax(BST* root){
    if(root==NULL){
        return -1;
    }
    else{
        while (root->right==NULL)
        {
            return root->data;
        }
    }
    return FindMax(root->right);
}
bool Search(BST* root,int x){
    BST* temp=root;
    //普通版
    // while(temp!=NULL){
    //     if(temp->data==x)
    //         return true;
    //     else if(x<temp->data){
    //         temp=temp->left;
    //     }else{
    //         temp=temp->right;
    //     }
    // }
    // return false;
    
    //递归版
    if(root==NULL){
        return false;
    }else if(x==root->data){
        return true;
    }
    else if (x<root->data)
    {
        return Search(root->left,x);
    }else if (x>root->data)
    {   
        return Search(root->right,x);
    }
    return false;

}

//查树的高度
int FindHeight(BST* root){
    if(root==NULL){
        return -1;
    }
    return MAX(FindHeight(root->left),FindHeight(root->right))+1;
}
//Binary Search Tree Traversal

//Breadth first
//Level Order Traversal 
void LevelOrder(BST* root){
    if(root==NULL){
        printf("tree is NULL");
    }

    Queue q;
    InitQueue(&q);
    EnQueue(root, &q); // 根节点先入队

    while (!IsEmpty(&q))
    {
        // 取出队首节点
        BST* cur = DeQueue(&q);
        printf("%d ", cur->data); // 访问当前节点

        // 左子树不为空，入队
        if (cur->left != NULL)
            EnQueue(cur->left, &q);
        // 右子树不为空，入队
        if (cur->right != NULL)
            EnQueue(cur->right, &q);
    }
}

//Depth first
//PreOrder InOrder PostOrder
void PreOrder(BST* root){
    if(root==NULL){
        return ;
    }
    printf("%d ",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
    
}
void InOrder(BST* root){
    if(root==NULL){
        return ;
    }
    InOrder(root->left);
    printf("%d ",root->data);
    InOrder(root->right);
    
}
void PostOrder(BST* root){
    if(root==NULL){
        return ;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ",root->data);

    
}
int main(){
    BST* root=NULL;
    BST** rootPtr=&root;
    Insert(rootPtr,9);
    Insert(rootPtr,2);
    Insert(rootPtr,5);
    Insert(rootPtr,11);
    Insert(rootPtr,15);
    Insert(rootPtr,13);
    Insert(rootPtr,4);
    Insert(rootPtr,1);
    Insert(rootPtr,7);
    // root=Insert(root,1);
    // root=Insert(root,2);
    // root=Insert(root,5);
    // root=Insert(root,8);
    // root=Insert(root,6);
    if(Search(root,5)){
        printf("find\n");
    }else{
        printf("wrong\n");
    }
    printf("Min= ");
    printf("%d\n",FindMin(root));
    printf("Max= ");
    printf("%d\n",FindMax(root));
    printf("%d \n",FindHeight(root));

    printf("层序遍历结果：");
    LevelOrder(root);
    printf("先序遍历结果");
    PreOrder(root);
    printf("中序遍历结果");
    InOrder(root);
    printf("后序遍历");
    PostOrder(root);
    return 0;
}