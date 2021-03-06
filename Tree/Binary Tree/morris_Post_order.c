
//Needs modification .you have to reverse every line and push it into queue and then print the queue.
//but i am printing line by line without reversing
//READ OUTPUT IN REVERSE ORDER FROM TOP TO BOTTOM FROM CONSOLE  FOR  POST ORDER 
//WILL ADD EXPLANATION IN FUTURE

#include<stdio.h>
#include<stdlib.h>
#include "Tree.h"

int count=0;


struct Node *createDummy(int data){
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=data;
    return temp;
}

morris_reverseStore(struct Node *start,struct Node *end){
    struct Node *i;
    for(i=start;i!=end;i=i->right){
        printf(" %d ",i->data);
    }
}

morrisPostOrder(struct Node *root){
    struct Node *dummy=createDummy(-1);
    dummy->left=root;
    dummy->right=NULL;

    struct Node *p=dummy;
    while(p){
            if(p->left==NULL){
                p=p->right;
            }
            else{
                struct Node *temp=p->left;

                while(temp->right!=NULL && temp->right!=p)
                    temp=temp->right;
                if(temp->right==NULL){
                    temp->right=p;
                    p=p->left;
                }
                else{
                    morris_reverseStore(p->left,p);
                    printf("\n");
                    temp->right=NULL;
                    p=p->right;
                }

            }
    }
}

postOrder(struct Node *root,int *count){
    if(root==NULL)
        return;
    postOrder(root->left,count);
    postOrder(root->right,count);
    *count=*count+1;
    printf(" %d ",root->data);
}

main(){

    struct Node *root=getTree();

    printf("Post Order with recursion\n");
    postOrder(root,&count);
    printf("\n\nMorris Post order traversal without stack/without recursion \n");
    printf("PLEASE READ EACH LINE FROM TOP TO BOTTOM IN REVERSE ORDER FOR POST ORDER(WILL MODIFY CODE SHORTLY)\n\n");
    morrisPostOrder(root);

}
