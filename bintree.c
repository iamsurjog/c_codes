#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node *left, *right;
}node;

// defining a max function for ease of use in height function

int max(int a, int b){
    if (a>b){
        return a;
    }
    return b;
}

// using linked list instead of queue because easier

typedef struct lnode{
    node *val;
    struct lnode *next;
}lnode;


lnode* iterate(lnode *n){
    while (n->next != NULL){
    n = n->next;
    }
    return n;
}

void append(lnode *n, node *val){
    lnode *tail = iterate(n);
    lnode *new_node = (lnode*)malloc(sizeof(lnode));
    new_node->val = val;
    new_node->next = NULL;
    tail->next = new_node;
}


// code for the bin tree


void add(node *n, int a, int b){
    node *left = (node*)malloc(sizeof(node));
    node *right = (node*)malloc(sizeof(node));
    left->val = a;
    right->val = b;
    n->left = left;
    n->right = right;
    left->left = left->right = right->left = right->right = NULL;
}

node* createnode(int val){
    node *n = (node*)malloc(sizeof(node));
    n->left = n->right = NULL;
    n->val = val;
}

void dfs(node *n){
    if (n == NULL){
        return;
    }
    dfs(n->left);
    dfs(n->right);
        printf("%d, ", n->val);

}

void bfs_calc(lnode *q){
    printf("%d, ", q->val->val);
    if ((q->val->left != NULL) | (q->val->right != NULL) | (q->next!=NULL)){
        if(q->val->left != NULL){
            append(q, q->val->left);
        }
        if(q->val->right != NULL){
            append(q, q->val->right);
        }
        bfs_calc(q->next);
    }
    return;
}

void bfs(node *n){
    lnode *q = (lnode*)malloc(sizeof(lnode));
    node *temp = n;
    q->val = n;
    q->next = NULL;
    bfs_calc(q);

    
}


int height(node *n){
    if (n==NULL){
        return 0;
    }
    int ldepth = height(n->left) + 1;
    int rdepth = height(n->right) + 1;

    return max(ldepth, rdepth);
}

int main(){
    node *root = (node*)malloc(sizeof(node));
    root->val = 30;
    root->left = NULL;
    root->right = NULL;
    add(root, 20, 39);
    add(root->left, 10, 25);
    add(root->right, 35, 42);
    add(root->left->left, 0, 15);
    add(root->left->right, 23, 0);
    dfs(root);
    printf("\n");
    // bfs(root);
    printf("%d", height(root));
    // printf("%d, %d, %d", root->val, root->left->val, root->right->val);
    return 0;
}