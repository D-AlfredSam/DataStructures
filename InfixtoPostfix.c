#include<stdio.h>
#include<stdlib.h>
struct node{
        char data;
        struct node*next;
};
struct node*head=NULL;
void insert(char x){
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        temp->next=head;
        head=temp;
    }
}
void pop(char x){
   struct node*ptr;
   while(head->data!=x){
       ptr=head;
        printf("%c",head->data);
        head=head->next;
        free(ptr);
   }
   ptr=head;
   head=head->next;
   free(ptr);
}
void popsign(){
    struct node*ptr;
    ptr=head;
    printf("%c",head->data);
    head=head->next;
    free(ptr);
}
void leftout(){
    struct node*ptr;
    while(head){
        ptr=head;
        printf("%c",head->data);
        head=head->next;
        free(ptr);
    }
}
int main(){
        char exp[100];
        scanf("%s",&exp);
        for(int i=0;i<strlen(exp);i++){
            
                switch(exp[i]){
                    case ')':
                        pop('(');
                        break;
                    case ']':
                        pop('[');
                        break;
                    case '}':
                        pop('{');
                        break;
                    case '+':
                    case '-':    
                    case '/':
                    case '*':
                    case '(':
                    case '{':
                    case '[':
                        insert(exp[i]);
                        break;
                    default:
                        
                        printf("%c",exp[i]);  
                        if (exp[i-1]=='/' || exp[i-1]=='*' || exp[i-1]=='%')
                            popsign();
                }    
        }            
        leftout();
        return 0;
}