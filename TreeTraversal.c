#include <stdio.h>
#include <stdlib.h>
struct node {
 int item;
 struct node* left;
 struct node* right;
};
struct node* root=NULL;

struct node* where(struct node *ptr,int val){
    if(ptr->item>val){
        if(ptr->left!=NULL)
            ptr=where(ptr->left,val);
    }
    else if(ptr->item<val){
        if(ptr->right!=NULL)
            ptr=where(ptr->right,val);
    }
    return ptr;
}

void insert(){
    struct node*temp;
    struct node*temp_ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->left=NULL;
    temp->right=NULL;
    printf("enter value:");
    scanf("%d",&temp->item);
    if(root==NULL)
        root=temp;
    else{
        temp_ptr=where(root,temp->item);
        if(temp_ptr->item>temp->item)
            temp_ptr->left=temp;
        else if(temp_ptr->item<temp->item)    
            temp_ptr->right=temp;
    }
}

// Inorder traversal
void inorderTraversal(struct node* root) {
 if (root == NULL) return;
 inorderTraversal(root->left);
 printf("%d ->", root->item);
 inorderTraversal(root->right);
}
// Preorder traversal
void preorderTraversal(struct node* root) {
 if (root == NULL) return;
 printf("%d ->", root->item);
 preorderTraversal(root->left);
 preorderTraversal(root->right);
}
// Postorder traversal
void postorderTraversal(struct node* root) {
 if (root == NULL) return;
 postorderTraversal(root->left);
 postorderTraversal(root->right);
 printf("%d ->", root->item);
}



int main() {
 int choice;
 do{
     printf("\nchoose an option below:\n");
     printf("1. insert\n2. preorderTraversal \n3. inorderTraversal\n4. postorderTraversal\n5. exit:\n");
     scanf("%d",&choice);
     switch(choice){
         case 1:
             insert();
             break;
         case 2:
             printf("\nPreorder traversal \n");
             preorderTraversal(root);    
             break;
         case 3:
             printf("\nInorder traversal \n");
             inorderTraversal(root);   
             break;
         case 4:
             printf("\nPostorder traversal \n");
             postorderTraversal(root); 
             break;
         case 5:
             printf("exiting code...\n"); 
             return 0;   
         default:
             printf("the option is invalid. kindly verify the specified options:\n");    
     }
 } while (choice);
 return 0;
}