#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node *left;
    struct node *right;
}node;

typedef struct lnode{
    node *val;
    struct lnode *next;
}lnode;

void dfs_inorder(node *n){
    if (n == NULL){
        return;
    }
    dfs_inorder(n->left);
    printf("%d, ", n->val);
    dfs_inorder(n->right);
}

void dfs_preorder(node *n){
    if (n == NULL){
        return;
    }
    printf("%d, ", n->val);
    dfs_preorder(n->left);
    dfs_preorder(n->right);
}

void dfs_postorder(node *n){
    if (n == NULL){
        return;
    }
    dfs_postorder(n->left);
    dfs_postorder(n->right);
    printf("%d, ", n->val);
}

void append(node *n, int val){
    if (n->val > val){
        if (n->left == NULL){
            node *nw = (node*)malloc(sizeof(node));
            nw->val = val;
            nw->left = nw->right = NULL;
            n->left = nw;            
        }else{
            append(n->left, val);
        }
    }
    if (n->val < val){
        if (n->right == NULL){
            node *nw = (node*)malloc(sizeof(node));
            nw->val = val;
            nw->left = nw->right = NULL;
            n->right = nw;            
        }else{
            append(n->right, val);
        }
    }
}

node* remove(node *n, int a){
    if (n == NULL)
        return n;

    if (n->val > a)
        n->left = remove(n->left, a);
    else if (n->val < a)
        n->right = remove(n->right, a);

    else {

        if (n->left == NULL) {
            node* temp = n->right;
            return temp;
        }

        if (n->right == NULL) {
            node* temp = n->left;
            return temp;
        }

        // Smallest right child
        node* temp = n;
        temp = temp->right;
        while (temp->left != NULL)
            temp = temp->left;
        n->val = temp->val;
        n->right = remove(temp->right, temp->val);
    }
    return n;
}

// void bfs_calc(lnode *q){
//     printf("%d, ", q->val->val);
//     if ((q->val->left != NULL) | (q->val->right != NULL) | (q->next!=NULL)){
//         if(q->val->left != NULL){
//             append(q, q->val->left);
//         }
//         if(q->val->right != NULL){
//             append(q, q->val->right);
//         }
//         bfs_calc(q->next);
//     }
//     return;
// }

// void bfs(node *n){
//     lnode *q = (lnode*)malloc(sizeof(lnode));
//     node *temp = n;
//     q->val = n;
//     q->next = NULL;
//     bfs_calc(q);

    
// }

int main(){
    node *root = (node*)malloc(sizeof(node));
    root->val = 54;
    root->left = root->right = NULL;
    append(root, 6);
    append(root, 25);
    append(root, 84);
    append(root, 60);
    append(root, 65);
    append(root, 30);
    append(root, 9);
    append(root, 21);
    append(root, 10);
    // bfs(root);
    dfs_inorder(root);
    printf("\n");
    dfs_preorder(root);
    // printf("\n%d", root->left->right->left->val);
    printf("\n");
    remove(root, 6);
    dfs_inorder(root);
    printf("\n");
    dfs_postorder(root);
    return 0;
}