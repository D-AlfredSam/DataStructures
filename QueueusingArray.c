#include <stdio.h>
#include <stdlib.h>

int queue[1000];
int front=-1,rear=-1,n;

int isfull();
int isempty();
void enqueue();
void dequeue();
void peek();
void back();
void print();

void main()
{
    printf("ENTER THE SIZE ");
    scanf("%d",&n);
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

int isfull()
{
    if(rear==n-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty()
{
    if(front==-1 && rear==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue()
{
    int x;
    if(isfull())
    {
        printf("OVERFLOW ");
    }
    else
    {
        printf("ENTER THE DATA ");
        scanf("%d",&x);
        
        if(isempty())
        {
            front=rear=0;
            queue[rear]=x;
        }
        else
        {
            rear++;
            queue[rear]=x;
        }
    }
}

void dequeue()
{
    int x;
    
    if(isempty())
    {
        printf("UNDERFLOW ");
    }
    else
    {
        if(rear==front)
        {
            x=queue[front];
            front=rear=-1;
        }
        else
        {
            x=queue[front];
            front++;
        }
        printf("THE DELETED ELEMENT IS ");
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
        printf("THE FRONT ELEMENT IS ");
        printf("%d ",queue[front]);
    }
}

void back()
{
    if(isempty())
    {
        printf("EMPTY LIST ");
    }
    else
    {
        printf("THE REAR ELEMENT IS ");
        printf("%d ",queue[rear]);
    }
}

void print()
{
    int temp;
    
    if(isempty())
    {
        printf("EMPTY LIST ");
    }
    else
    {
        temp=front;
        printf("THE DATAS IN QUEUE ARE ");
        while(temp<=rear)   #while(temp!=rear)   the one more same print stmnt out of while
        {
            printf("%d ",queue[temp]);
            temp++;
        }
    }
}
