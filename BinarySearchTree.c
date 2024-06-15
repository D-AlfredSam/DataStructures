#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;
struct node *temp;

struct node *creation(int);
struct node *insertion(struct node *,int);
struct node *deletion(struct node *,int);
struct node *findmin(struct node *);
struct node *findmax(struct node *);
void Findmin(struct node *);
void Findmax(struct node *);
void Find(struct node *,int);
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);

void main()
{
    int choice;
    do
    {
        printf("Enter the choice ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
            {
            int a;
            printf("Enter the data to be inserted ");
            scanf("%d",&a);
            root=insertion(root,a);
            break;
            }
            case 2:
            {
            int b;
            printf("Enter the data to be deleted ");
            scanf("%d",&b);
            root=deletion(root,b);
            break;
            }
            case 3:
            temp=findmin(root);
            if(temp!=NULL)
            {
            printf("The smallest data in the tree is %d ",temp->data);
            }
            break;
            case 4:
            temp=findmax(root);
            if (temp!=NULL)
            {
            printf("The largest data in the tree is %d ",temp->data);
            }
            break;
            case 5:
            Findmin(root);
            break;
            case 6:
            Findmax(root);
            break;
            case 7:
            {
            int c;
            printf("The data to be searched is ");
            scanf("%d",&c);
            Find(root,c);
            break;
            }
            case 8:
            preorder(root);
            break;
            case 9:
            inorder(root);
            break;
            case 10:
            postorder(root);
            break;
            default:
            printf("Invalid choice ");
        }
    }while(choice!=0);
}

struct node *creation (int e)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    
    if (newnode==NULL)
    {
        printf("Overflow ");
    }
    else
    {
        newnode->data=e;
        newnode->right=NULL;
        newnode->left=NULL;
        
        return newnode;
    }
}

struct node *insertion(struct node *tree,int e)
{
   if (tree==NULL) 
   {
       tree=creation(e);
       
       return tree;
   }
   else
   {
       if (e<tree->data)
       {
           tree->left=insertion(tree->left,e);
       }
       else if(e>tree->data)
       {
           tree->right=insertion(tree->right,e);
       }
       
       return tree;
   }
}

struct node *deletion(struct node *tree,int f)
{
    if(tree==NULL)
    {
        printf("Underflow ");
        return NULL;
    }
    else
    {
        if (f<tree->data)
        {
            tree->left=deletion(tree->left,f);
        }
        else if(f>tree->data)
        {
            tree->right=deletion(tree->right,f);
        }
        else
        {
            if(tree->left!=NULL && tree->right!=NULL)
            {
                temp=findmin(tree->right);
                tree->data=temp->data;
                tree->right=deletion(tree->right,temp->data);
                
                
            }
            else if(tree->left==NULL && tree->right==NULL)
            {
                temp=tree;
                
                free(temp);
                return NULL;
            }
            else
            {
                temp=tree;
               if(tree->left==NULL)
               {
                   tree=tree->right;
               }
               else if(tree->right==NULL)
               {
                   tree=tree->left;
               }
               
               free(temp);
            }
        }
        return tree; 
    }
}

struct node *findmin(struct node *tree)
{
    if (tree==NULL)
    {
        printf("Empty tree ");
        return NULL;
    }
    else
    {
        temp=tree;
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        
        return temp;
    }
}

struct node *findmax(struct node *tree)
{
    if (tree==NULL)
    {
        printf("Empty tree ");
        return NULL;
    }
    else
    {
        temp=tree;
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        
        return temp;
    }
}

void Findmin(struct node *tree)
{
    if (tree==NULL)
    {
        printf("Empty tree ");
    }
    else
    {
        temp=tree;
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        
        printf("The smallest data is the tree is %d ",temp->data);
    }
}

void Findmax(struct node *tree)
{
    if (tree==NULL)
    {
        printf("Empty tree ");
    }
    else
    {
        temp=tree;
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        
        printf("The largest data is the tree is %d ",temp->data);
    }
}

void Find(struct node *tree,int g)
{
    if (tree==NULL)
    {
        printf("Not found ");
    }
    else
    {
        if(g<tree->data)
        {
            Find(tree->left,g);
        }
        else if(g>tree->data)
        {
            Find(tree->right,g);
        }
        else
        {
            printf("Element found ");
        }
    }
}

void preorder(struct node *tree)
{
    if (tree!=NULL)
    {
        printf("%d ",tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void inorder(struct node *tree)
{
    if(tree!=NULL)
    {
        inorder(tree->left);
        printf("%d ",tree->data);
        inorder(tree->right);
    }
}

void postorder(struct node *tree)
{
    if(tree!=NULL)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ",tree->data);
    }
}
