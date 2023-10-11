 #include <stdio.h>
#include <stdlib.h>

typedef struct btnode{
	int data;
	struct btnode* left;
	struct btnode* right;
}btnode;

btnode* Node(int n){
	btnode* head=(btnode*)malloc(sizeof(btnode));
	head->data=n;
	head->left=NULL;
	head->right=NULL;
	return head;
	
}

void inorder(btnode* root){
    if(root == NULL){
        printf("root is NULL");
        return;
    }
	if(root){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

void preorder(btnode* root){
    if(root == NULL){
        printf("root is Null");
        return;
    }
	if(root){
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(btnode* root){
    if(root == NULL){
        printf("root is null");
        return ;
    }
	if(root){
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
btnode* insert (btnode* root,int val ){
    if(root == NULL){
        return Node(val);
    }
    printf("\nenter 1 to insert in leftsubtree\n");
    printf("enter 2 to insert in right subtree\n");
    int choice;
    printf("enter choice to insert");
    scanf("%d",&choice);
    switch(choice){
        case 1: root->left = insert(root->left,val);
                break;
        case 2: root->right = insert(root->right,val);
                break;
        default: printf("invalid choice");
    }
    
}

int main(){
	btnode* root =NULL;
    int val,choice;
    while(1){
        printf("\nenter 1 for create tree\n");
        printf("enter 2 for insertion\n");
        printf("enter 3 for inorder\n");
        printf("enter 4 for preorder\n");
        printf("enter 5 for post order\n");
        printf("enter 6 to exit\n");
        printf("enter choice");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("enter value of root");
                    scanf("%d",&val);
                    root =(btnode*)malloc(sizeof(btnode));
                    root->data =val;
                    root->left = NULL;
                    root->right = NULL;
                    break;
            case 2 :printf("enter value to be inserted");
                    scanf("%d",&val);
                    insert(root,val);
                    break;
            case 3 :printf("inorder traversal is\n");
                    inorder(root);
                    break;
            case 4 : printf("preorder travesal is \n");
                     preorder(root);
                     break;
            case 5 : printf("postorder traversal is\n");
                     postorder(root);
                     break;
            case 6 : exit(0);
            default: printf("invalid choice");
        }

    }

	
}
