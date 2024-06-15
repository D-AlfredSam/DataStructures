#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
};

struct node *head=NULL;

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
        newnode->next==NULL;
        
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            newnode->next=head;
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
            delnode->next==NULL;
            
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
        printf("THE DATAS IN THE SINGLY LINKED LIST ARE ");
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
    newnode=(struct node*)malloc(sizeof(newnode));
    
    if(newnode==NULL)
    {
        printf("OVERFLOW ");
    }
    else
    {
        printf("ENTER THE DATA ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        
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
        }
    }
}

void deletionb()
{
    struct node *delnode,*temp;
    
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
            delnode->next=NULL;
            
            free(delnode);
        }
        else
        {
            delnode=head;
            while(delnode->next!=NULL)
            {
                temp=delnode;
                delnode=delnode->next;
            }
            temp->next=NULL;
      
            
            free(delnode);
        }
    }
}

void searching()
{
    struct node *node;
    int flag=1,x,i=1;
    
    if(head==NULL)
    {
        printf("EMPTY LIST ");
    }
    else
    {
        printf("ENTER THE VALUE ");
        scanf("%d",&x);
        
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
                node=node->next;
                i++;
            }
        }
        
        if(flag)
        {
            printf("VALUE NOT FOUND ");
        }
    }
}

void insertionc()
{
    struct node *newnode,*temp1,*temp2;
    int pos,i=1,count=1;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("ENTER THE POS ");
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
        
        if(pos==1)
        {
            if(head==NULL)
            {
                head=newnode;
            }
            else
            {
                newnode->next=head;
                head=newnode;
            }
        }
        else
        {
            temp1=head;
            while(temp1->next!=NULL)
            {
                temp1=temp1->next;
                count++;
            }
            
            if(pos<=count)
            {
                temp2=head;
                while(i<pos)
                {
                    temp1=temp2;
                    temp2=temp2->next;
                    i++;
                }
                temp1->next=newnode;
                newnode->next=temp2;
            }
            else if(pos==count+1)
            {
                temp1=head;
                while(temp1->next!=NULL)
                {
                    temp1=temp1->next;
                }
                temp1->next=newnode;
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
    struct node *delnode,*temp1;
    int count=1,pos,i=1;
    printf("ENTER THE POS ");
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
                delnode->next=NULL;
                
                free(delnode);
            }
            else
            {
                delnode=head;
                head=delnode->next;
                delnode->next=NULL;
                
                free(delnode);
            }
        }
        else
        {
            temp1=head;
            while(temp1->next!=NULL)
            {
                temp1=temp1->next;
                count++;
            }
            if(pos<=count)
            {
                delnode=head;
                while(i<pos)
                {
                    temp1=delnode;
                    delnode=delnode->next;
                    i++;
                }
                temp1->next=delnode->next;
                delnode->next=NULL;
                
                free(delnode);
            }
            else
            {
                printf("POSITION IS NOT IN THE LIST ");
            }
        }
    }
    
}
