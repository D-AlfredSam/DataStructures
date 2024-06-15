#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front=NULL,*rear=NULL;

int isempty();
void enqueue();
void dequeue();
void peek();
void back();
void print();

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
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                back();
                break;
            case 5:
                print();
                break;
            case 6:
                exit(0);
                break;
        }
    }while(choice!=6);
}

int isempty()
{
    if(front==NULL && rear==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void print()
{
    struct node *nodes;
    
    if(isempty())
    {
        printf("UNDERFLOW ");
    }
    else
    {
        nodes=front;
        printf("THE DATAS IN QUEUE USING LINKED LIST ARE ");
        while(nodes!=rear)
        {
            printf("%d ",nodes->data);
            nodes=nodes->next;
        }
        printf("%d ",nodes->data);
    }
}

void enqueue()
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
        newnode->next=NULL;
        
        if(isempty())
        {
            front=rear=newnode;
        }
        else
        {
            rear->next=newnode;
            rear=newnode;
        }
    }
}

void dequeue()
{
    struct node *delnode;
    
    if(isempty())
    {
        printf("UNDERFLOW ");
    }
    else
    {
        if(rear==front)
        {
            delnode=front;
            printf("THE DELETED DATA IS ");
            printf("%d ",delnode->data);
            rear=front=NULL;
            
            free(delnode);
        }
        else
        {
            delnode=front;
            printf("THE DELETED DATA IS ");
            printf("%d ",delnode->data);
            front=front->next;
            
            free(delnode);
        }
    }
}

void peek()
{
    if(isempty())
    {
        printf("UNDERFLOW ");
    }
    else
    {
        printf("THE FRONT ELEMENT IS ");
        printf("%d ",front->data);
    }
}

void back()
{
    if(isempty())
    {
        printf("UNDERFLOW ");
    }
    else
    {
        printf("THE REAR ELEMENT IS ");
        printf("%d ",rear->data);
    }
}
