#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} bstnode;

bstnode* createNode(int key) {
    bstnode* newNode = (bstnode*)malloc(sizeof(bstnode));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bstnode* insertKey(bstnode* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insertKey(root->left, key);
    } else if (key > root->key) {
        root->right = insertKey(root->right, key);
    }

    return root;
}
bool keyExist(bstnode* root,int key){
    if(root == NULL){
        return false;
    }
    if(root->key> key){
        return keyExist(root->left,key) ;

    }
    else if(root->key == key){
        return true;
    }
    else{
        return keyExist(root->right,key);
    }
}

bstnode* searchKey(bstnode* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return searchKey(root->left, key);
    }

    return searchKey(root->right, key);
}

bstnode* findPredecessor(bstnode* root) {
    if (root == NULL) {
        return NULL;
    }

    bstnode* current = root->left;
    while (current && current->right) {
        current = current->right;
    }

    return current;
}

bstnode* findSuccessor(bstnode* root) {
    if (root == NULL) {
        return NULL;
    }

    bstnode* current = root->right;
    while (current && current->left) {
        current = current->left;
    }

    return current;
}

bstnode* deleteKey(bstnode* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteKey(root->left, key);
    } else if (key > root->key) {
        root->right = deleteKey(root->right, key);
    } else {
        if (root->left == NULL) {
            bstnode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            bstnode* temp = root->left;
            free(root);
            return temp;
        }

        bstnode* temp = findSuccessor(root);
        root->key = temp->key;
        root->right = deleteKey(root->right, temp->key);
    }

    return root;
}

void inOrderTraversal(bstnode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->key);
        inOrderTraversal(root->right);
    }
}

int main() {
    bstnode* Root = NULL;
    int choice, key;

    do {
        printf("\nMenu:\n");
        printf("1. Create a binary search tree (with input)\n");
        printf("2. Search for a key\n");
        printf("3. Find in-order predecessor and successor of a node\n");
        printf("4. Insert a key\n");
        printf("5. Delete a key\n");
        printf("6. In-order traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the root key: ");
                scanf("%d", &key);
                Root = createNode(key);
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                bstnode* result = searchKey(Root, key);
                if (result != NULL) {
                    printf("Key %d found in the tree.\n", key);
                } else {
                    printf("Key %d not found in the tree.\n", key);
                }
                break;
            case 3:
                printf("Enter the key of the node: ");
                scanf("%d", &key);
                bstnode* node = searchKey(Root, key);
                if (node != NULL) {
                    bstnode* pred = findPredecessor(node);
                    bstnode* succ = findSuccessor(node);

                    printf("In-order predecessor: %d\n", pred ? pred->key : -1);
                    printf("In-order successor: %d\n", succ ? succ->key : -1);
                } else {
                    printf("Node with key %d not found.\n", key);
                }
                break;
            case 4:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                Root = insertKey(Root, key);
                break;
            case 5:
                if(Root == NULL){
                    printf("root is null");
                    break;
                }
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                if(keyExist(Root,key)== false){
                    printf("key does not exist");
                    break;
                }
                Root = deleteKey(Root, key);
                break;
            case 6:
                printf("In-order traversal: ");
                inOrderTraversal(Root);
                printf("\n");
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. \n");
                break;
        }
    } while (choice != 7);

    return 0;
}
