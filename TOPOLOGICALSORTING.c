#include<stdio.h>
#include<stdlib.h>
struct vertex {
    int data;
    int visit;
    struct vertex *next;
    struct adjacent*head;
}*head=NULL;

struct adjacent {
    int data;
    int weight;
    struct adjacent*next;
}*aja_head=NULL;

struct node {
    int data;
    struct node*next;
}*result=NULL;

void insert(int a) {
    struct vertex*ptr;
    int count;
    ptr=malloc(sizeof(struct vertex));
    printf("enter value of vertex %d: ",a);
    scanf("%d",&ptr->data);
    printf("enter the number of nodes that are adjacent: ");
    scanf("%d",&count);
    if(count) {
        for(int i=0; i<count; i++) {
            struct adjacent*node;
            node=malloc(sizeof(struct adjacent));
            printf("enter the value of adjacent vertex %d: ",i+1);
            scanf("%d",&node->data);
            node->weight = 0;
            if(aja_head==NULL) {
                node->next=NULL;
                aja_head=node;
            }
            else {
                node->next=aja_head;
                aja_head=node;
            }
        }
        ptr->head=aja_head;
    }
    else {
        ptr->head=NULL;
    }
    if(head==NULL) {
        ptr->next=NULL;
        head=ptr;
    }
    else {
        ptr->next=head;
        head=ptr;
    }
    aja_head=NULL;
}

void display() {
    struct vertex*ptr=head;
    while(ptr) {
        printf("%d ",ptr->data);
        if(ptr->head) {
            struct adjacent*temp=ptr->head;
            while(temp) {
                printf("->%d ",temp->data);
                temp=temp->next;
            }
        }
        printf("\n");
        ptr=ptr->next;
    }
}

void Topological_sorting() {
    struct vertex*ptr;
    ptr=head;
    while(ptr) {
        if(ptr->head) {
            struct adjacent*aja_ptr=ptr->head;
            int count=0;
            int aja_count=0;
            while(aja_ptr) {
                count++;
                aja_ptr=aja_ptr->next;
            }
            struct node*res_ptr=result;
            while(res_ptr) {
                aja_ptr=ptr->head;
                while(aja_ptr) {
                    if(aja_ptr->data==res_ptr->data)
                        aja_count++;
                    aja_ptr=aja_ptr->next;
                }
                res_ptr=res_ptr->next;
            }

            if(aja_count<count) {
                struct node*temp;
                temp=malloc(sizeof(struct node));
                temp->data=ptr->data;
                temp->next=NULL;
                if(result==NULL) {
                    result=temp;
                }
                else {
                    struct node*temp_head=result;
                    while(temp_head->next) {
                        temp_head=temp_head->next;
                    }
                    temp_head->next=temp;
                }
            }
        }
        ptr=ptr->next;
    }
    ptr=head;
    while(ptr) {
        int flag=1;
        struct node*temp=result;
        while(temp->next) {
            if(temp->data==ptr->data)
                break;
            temp=temp->next;
        }
        if(temp->data==ptr->data)
            flag=0;
        if(flag) {
            struct node*temp_ptr;
            temp_ptr=malloc(sizeof(struct node));
            temp_ptr->data=ptr->data;
            temp_ptr->next=NULL;
            temp->next=temp_ptr;
        }
        ptr=ptr->next;
    }
    struct node*temp_head=result;
    while(temp_head) {
        printf("%d ",temp_head->data);
        temp_head=temp_head->next;
    }
}

int main() {
    int count;
    printf("enter the number of vertex: ");
    scanf("%d",&count);
    for(int i=0; i<count; i++) {
        insert(i+1);
    }
    display();
    printf("Topological Sorting:\n");
    Topological_sorting();
}