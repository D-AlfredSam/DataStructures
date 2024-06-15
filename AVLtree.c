#include <stdio.h>
#include <stdlib.h>
struct node {
    int item;
    int height;
    int balance_factor;
    struct node* left;
    struct node* right;
};
struct node* root=NULL;
int height(struct node*);
void postorderTraversal(struct node*);
struct node isviolate(struct node,int);
struct node * selector(struct node*,int);
struct node * RR_rotation(struct node*);
struct node * LL_rotation(struct node*);
int abs(int a){
    if (a>=0)
        return a;
    else
        return -a;   
}
struct node* where(struct node *ptr,int val) {
    if(ptr->item>val) {
        if(ptr->left!=NULL)
            ptr=where(ptr->left,val);
    }
    else if(ptr->item<val) {
        if(ptr->right!=NULL)
            ptr=where(ptr->right,val);
    }
    return ptr;
}

void insert() {
    struct node*temp;
    struct node*temp_ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->height=0;
    temp->balance_factor=0;
    temp->left=NULL;
    temp->right=NULL;
    printf("enter value:");
    scanf("%d",&temp->item);
    if(root==NULL)
        root=temp;
    else {
        temp_ptr=where(root,temp->item);
        if(temp_ptr->item>temp->item)
            temp_ptr->left=temp;
        else if(temp_ptr->item<temp->item)
            temp_ptr->right=temp;
        height(root);
    }
    if(abs(root->balance_factor)==2 && ((root->left && abs(root->left->balance_factor)==1) || (root->right && abs(root->right->balance_factor)==1)))
        root=selector(root, temp->item);
    else if(isviolate(root,temp->item)) {
        struct node*ptr = isviolate(root,temp->item);
        if(ptr->item>temp->item) {
            ptr->left = selector(ptr->left,temp->item);
        }
        else {
            ptr->right = selector(ptr->right,temp->item);
        }
    }
    height(root);
}

struct node*isviolate(struct node*root,int val) {
    if(root->item<val) {
        if(abs(root->right->balance_factor)==2 && ((root->right->left && abs(root->right->left->balance_factor)==1) || (root->right->right && abs(root->right->right->balance_factor)==1)))
            return root;
        return isviolate(root->right,val);
    }
    else if(root->item>val){
        if(abs(root->left->balance_factor)==2 && ((root->left->left && abs(root->left->left->balance_factor)==1) || (root->left->right && abs(root->left->right->balance_factor)==1)))
            return root;
        return isviolate(root->left,val);
    }
    else
        return NULL;
}

struct node* selector(struct node*ptr,int val) {
    if(ptr->item<val) {
        if(ptr->right->item<val){
            return RR_rotation(ptr);
        }
        else{
            ptr->right = LL_rotation(ptr->right);
            return RR_rotation(ptr);
        }
    }
    else {
        if(ptr->left->item>val)
            return LL_rotation(ptr);
        else {
            ptr->left = RR_rotation(ptr->left);
            return LL_rotation(ptr);
        }
    }
}

struct node* LL_rotation(struct node*ptr) {
    struct node*temp=ptr->left;
    ptr->left=temp->right;
    temp->right=ptr;
    return temp;
}

struct node* RR_rotation(struct node*ptr) {
    struct node*temp=ptr->right;
    ptr->right=temp->left;
    temp->left=ptr;
    return temp;
}


//height finding
int height(struct node* root) {
    int l=0,r=0;
    if(root->left==NULL)
        l=-1;
    else
        l=height(root->left);
    if(root->right==NULL)
        r=-1;
    else
        r=height(root->right);
    if(l==r) {
        root->height=l+1;
        root->balance_factor=0;
    }
    else {
        root->height= l>r?l+1:r+1;
        root->balance_factor=l-r;
    }
    return root->height;
}
// Postorder traversal
void postorderTraversal(struct node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ( %d, %d)->", root->item,root->height,root->balance_factor);
}



int main() {
    int choice;
    do {
        printf("\nchoose an option below:\n");
        printf("1. insert\n2. postorderTraversal\n3. exit:\n");
        scanf("%d",&choice);
        switch(choice) {
        case 1:
            insert();
            break;
        case 2:
            printf("\nPostorder traversal \n");
            postorderTraversal(root);
            break;
        case 3:
            printf("exiting code...\n");
            return 0;
        default:
            printf("the option is invalid. kindly verify the specified options:\n");
        }
    } while (choice);
    return 0;
}