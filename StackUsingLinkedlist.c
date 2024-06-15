#include <stdio.h>
#include <stdlib.h>

struct node 
{
    struct node *next;
    int data;
};

struct node *top=NULL;

int isempty();
void push();
void pop();
void peek();
void print();
void size();

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
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                print();
                break;
            case 5:
                size();
                break;
            case 6:
                exit(0);
                break;
        }
    }while(choice!=6);
}

int isempty()
{
    if(top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push()
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
        
        if(top==NULL)
        {
            top=newnode;
        }
        else
        {
            newnode->next=top;
            top=newnode;
        }
    }
}
   
void pop()
{
    struct node *delnode;
    int x;
    if(isempty())
    {
        printf("UNDERFLOW ");
    }
    else
    {
        delnode=top;
        x=delnode->data;
        top=top->next;
        delnode->next=NULL;
        
        free(delnode);
        printf("THE DELETED DATA IS ");
        printf("%d ",x);
    }
}

void peek()
{
    if(isempty())
    {
        printf("EMPTY LIST ");
    }
    else
    {
        printf("THE TOP ELEMENT IS ");
        printf("%d ",top->data);
    }
}

void print()
{
    struct node *temp;
    
    if(isempty())
    {
        printf("EMPTY LIST ");
    }
    else
    {
        temp=top;
        printf("THE DATAS IN THE STACK ARE ");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

void size()
{
    struct node *temp;
    int count=1;
    
    if(isempty())
    {
        printf("EMPTY LIST ");
    }
    else
    {
        temp=top;
        while(temp->next!=NULL)
        {
            temp=temp->next;
            count++;
        }
        printf("THE SIZE OF THE STACK IS ");
        printf("%d ",count);
    }
}
