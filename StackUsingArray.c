#include <stdio.h>
#include <stdlib.h>

int stack[1000];
int n;
int top=-1;

int isempty();
int isfull();
void push();
void pop();
void peek();
void print();

void main()
{
    int choice;
    printf("ENTER THE SIZE ");
    scanf("%d",&n);
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
                exit(0);
                break;
        }
    }while(choice!=5);
}

int isempty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull()
{
   if(top==n-1)
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
    int x;
    printf("ENTER THE DATA ");
    scanf("%d",&x);
    
    if(isfull())
    {
        printf("OVERFLOW ");
    }
    else
    {
       top++;
       stack[top]=x;
    }
}

void pop()
{
    int x;
    
    if(isempty())
    {
        printf("UNDERFLOW ");
    }
    else
    {
        x=stack[top];
        top--;
        
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
        printf("THE TOP ELEMENT IN THE STACK IS ");
        printf("%d ",stack[top]);
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
        temp=top;
        printf("THE DATAS IN STACK ARE ");
        while(temp!=-1)
        {
            printf("%d ",stack[temp]);
            temp--;
        }
    }
}
