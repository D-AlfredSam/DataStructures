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
}*bd_head=NULL,*result=NULL ;

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

void BFS(int count) {
    struct node*temp_head;
    int flag=1;
    temp_head=malloc(sizeof(struct node));
    temp_head->data=head->data;
    temp_head->next=NULL;
    bd_head=temp_head;
    while(temp_head) {
        struct vertex * temp=head;
        struct node*ptr;
        while(temp) {
            if(temp->data==temp_head->data) {
                struct adjacent*aja_ptr;
                aja_ptr=temp->head;
                while(aja_ptr) {
                    ptr=bd_head;
                    while(ptr->next) {
                        if(aja_ptr->data==ptr->data) {
                            flag=0;
                            break;
                        }
                        ptr=ptr->next;
                    }
                    if(ptr->data==aja_ptr->data)
                        flag=0;
                    if(flag) {
                        struct node*temp_ptr;
                        temp_ptr=malloc(sizeof(struct node));
                        temp_ptr->next=NULL;
                        temp_ptr->data=aja_ptr->data;
                        ptr->next=temp_ptr;
                    }
                    aja_ptr=aja_ptr->next;
                    flag=1;
                }
                break;
            }
            temp=temp->next;
        }
        temp_head=temp_head->next;
    }
    struct node*ptr=bd_head;
    while(ptr) {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

void DFS(int count) {
    struct node*temp_head;
    struct node*result_ptr;
    int flag=1,no_pop=1;
    temp_head=malloc(sizeof(struct node));
    result_ptr=malloc(sizeof(struct node));
    temp_head->data=head->data;
    temp_head->next=NULL;
    result_ptr->data=head->data;
    result_ptr->next=NULL;
    result=result_ptr;
    bd_head=temp_head;
    while(temp_head) {
        struct vertex * temp=head;
        struct node*ptr;
        struct node*res_ptr;
        while(temp) {
            if(temp->data==temp_head->data) {
                struct adjacent*aja_ptr;
                aja_ptr=temp->head;
                while(aja_ptr) {
                    ptr=bd_head;
                    res_ptr=result;
                    while(ptr->next) {
                        ptr=ptr->next;
                    }
                    while(res_ptr->next) {
                        if(aja_ptr->data==res_ptr->data) {
                            break;
                        }
                        res_ptr=res_ptr->next;
                    }
                    if(res_ptr->data==aja_ptr->data)
                        flag=0;
                    if(flag) {
                        struct node*temp_ptr;
                        temp_ptr=malloc(sizeof(struct node));
                        result_ptr=malloc(sizeof(struct node));
                        temp_ptr->next=NULL;
                        result_ptr->next=NULL;
                        temp_ptr->data=aja_ptr->data;
                        ptr->next=temp_ptr;
                        result_ptr->data=aja_ptr->data;
                        res_ptr->next=result_ptr;
                        break;
                    }
                    aja_ptr=aja_ptr->next;
                    flag=1;
                }
                if(aja_ptr==NULL) {
                    ptr=bd_head;
                    if(ptr->next==NULL){
                        no_pop=0;
                        temp_head=NULL;
                        break;
                    }
                    while(ptr->next->data!=temp_head->data) {
                        ptr=ptr->next;
                    }
                    free(ptr->next);
                    ptr->next=NULL;
                    temp_head=ptr;
                    no_pop=0;
                }
                break;
            }
            temp=temp->next;
        }
        if(no_pop) {
            temp_head=temp_head->next;
        }
        no_pop=1;
    }
    struct node*res_ptr=result;
    while(res_ptr) {
        printf("%d ",res_ptr->data);
        res_ptr=res_ptr->next;
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
    printf("BFS: ");
    BFS(count);
    printf("DFS: ");
    DFS (count);
}