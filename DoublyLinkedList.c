#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    struct node *next;
    int data;
};

struct node *head;

void insertiona();
void insertionb();
void insertionc();
void deletiona();
void deletionb();
void deletionc();
void searching();
void display();

void main()
{
    int choice;
    do
    {
        printf("ENTER THE CHOICE ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insertiona();
                break;
            case 2:    
                insertionb();
                break;
            case 3:    
                insertionc();
                break;
            case 4:
                deletiona();
                break;
            case 5:    
                deletionb();
                break;
            case 6:    
                deletionc();
                break;
            case 7:    
                searching();
                break;
            case 8:    
                display();
                break;
            case 9:    
                exit(0);
                break;
        }
    }
    while(choice!=9);
}

void insertiona()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    
    if(newnode==NULL)
    {
        printf("OVERFLOW ");
    }
    else
    {
        printf("ENTER THE DATA ");
        scanf("%d",&newnode->data);
        newnode->prev=NULL;
        newnode->next=NULL;
        
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            newnode->next=head;
            newnode->next->prev=newnode;
            head=newnode;
        }
    }
}

void deletiona()
{
    struct node *delnode;
    
    if(head==NULL)
    {
        printf("UNDERFLOW ");
    }
    else
    {
        if(head->next==NULL)
        {
            delnode=head;
            head=NULL;
            
            free(delnode);
        }
        else
        {
            delnode=head;
            head=delnode->next;
            head->prev==NULL;
            delnode->next=NULL;
            
            free(delnode);
        }
    }
}

 void display()
 {
     struct node *nodes;
     
     if(head==NULL)
     {
         printf("EMPTY LIST ");
     }
     else
     {
         nodes=head;
         printf("THE DATAS IN THE DOUBLY LINKED LIST ARE ");
         while(nodes!=NULL)
         {
             printf("%d ",nodes->data);
             nodes=nodes->next;
         }
     }
 }

void insertionb()
{
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    
    if(newnode==NULL)
    {
        printf("OVERFLOW ");
    }
    else
    {
        printf("ENTER THE DATA ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;
        
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;
        }
    }
}

void deletionb()
{
    struct node *delnode;
    
    if(head==NULL)
    {
        printf("UNDERFLOW ");
    }
    else
    {
        if(head->next==NULL)
        {
            delnode=head;
            head=NULL;
            
            free(delnode);
        }
        else
        {
            delnode=head;
            while(delnode->next!=NULL)
            {
                delnode=delnode->next;
            }
            delnode->prev->next=NULL;
            delnode->prev=NULL;
            
            free(delnode);
        }
    }
}

void searching()
{
    struct node *node;
    int x,flag=1,i=1;
    printf("ENTER THE VALUE ");
    scanf("%d",&x);
    
    if(head==NULL)
    {
        printf("EMPTY LIST ");
    }
    else
    {
        node=head;
        while(node!=NULL)
        {
            if(node->data==x)
            {
                printf("%d ",i);
                flag=0;
                break;
            }
            else
            {
                i++;
                node=node->next;
            }
        }
        if(flag)
        {
            printf("VALUE IS NOT FOUND ");
        }
    }
}

void insertionc()
{
    struct node *newnode,*temp;
    int count=1,i=1,pos;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("ENTER THE POSITION ");
    scanf("%d",&pos);
    
    if(newnode==NULL)
    {
        printf("OVERFLOW ");
    }
    else
    {
        printf("ENTER THE DATA ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;
        
        if(pos==1)
        {
            if(head==NULL)
            {
                head=newnode;
            }
            else
            {
                newnode->next=head;
                newnode->next->prev=newnode;
                head=newnode;
            }
        }
        else
        {
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
                count++;
            }
            
            if(pos<=count)
            {
                temp=head;
                while(i<pos)
                {
                    temp=temp->next;
                    i++;
                }
                newnode->next=temp;
                newnode->prev=temp->prev;
                newnode->prev->next=newnode;
                temp->prev=newnode;
            }
            else if(pos==count+1)
            {
                temp=head;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=newnode;
                newnode->prev=temp;
            }
            else
            {
                printf("POSITION IS NOT IN THE LIST ");
            }
        }
    }
}

void deletionc()
{
    struct node *delnode;
    int pos,count=1,i=1;
    printf("ENTER THE POSITION");
    scanf("%d",&pos);
    
    if(head==NULL)
    {
        printf("UNDERFLOW ");
    }
    else
    {
        if(pos==1)
        {
            if(head->next==NULL)
            {
                delnode=head;
                head=NULL;
                
                free(delnode);
            }
            else
            {
                delnode-head;
                head=delnode->next;
                head->prev=NULL;
                delnode->next=NULL;
                
                free(delnode);
            }
        }
        else
        {
            delnode=head;
            while(delnode->next!=NULL)
            {
                delnode=delnode->next;
                count++;
            }
            
            if(pos<=count)
            {
                delnode=head;
                while(i<pos)
                {
                    delnode=delnode->next;
                    i++;
                }
                delnode->prev->next=delnode->next;
                delnode->next->prev=delnode->prev;
                delnode->next=NULL;
                delnode->prev=NULL;
                
                free(delnode);
            }
            else
            {
                printf("POSITION IS NOT FOUND ");
            }
        }
    }
}
