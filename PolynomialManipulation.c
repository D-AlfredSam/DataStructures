#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int coeff;
    int exp;
    struct Node * next;
}* poly1 = NULL,*poly2=NULL,*result=NULL;

void create1() {
    struct Node * t, * last = NULL;
    int num, i;

    printf("Enter number of terms: ");
    scanf("%d", & num);
    printf("Enter each term with coeff and exp:\n");

    for (i = 0; i < num; i++) {
        t = (struct Node * ) malloc(sizeof(struct Node));
        scanf("%d%d", & t -> coeff, & t -> exp);
        t -> next = NULL;
        if (poly1 == NULL) {
            poly1 = last = t;
        } else {
            last -> next = t;
            last = t;
        }
    }
}

void create2() {
    struct Node * t, * last = NULL;
    int num, i;

    printf("Enter number of terms: ");
    scanf("%d", & num);
    printf("Enter each term with coeff and exp:\n");

    for (i = 0; i < num; i++) {
        t = (struct Node * ) malloc(sizeof(struct Node));
        scanf("%d%d", & t -> coeff, & t -> exp);
        t -> next = NULL;
        if (poly2 == NULL) {
            poly2 = last = t;
        } else {
            last -> next = t;
            last = t;
        }
    }
}


void Display(struct Node * p) {
    printf("(%dx^%d) ", p -> coeff, p -> exp);
    p = p -> next;

    while (p) {
        printf("+ (%dx^%d)", p -> coeff, p -> exp);
        p = p -> next;
    }
    printf("\n");
}

void add(struct Node * p1, struct Node * p2) {
    struct Node * t, * last = NULL;
    int num1,num2;
    int p;
    if(p1->exp>p2->exp)
        p=p1->exp;
    else
        p=p2->exp;

    while (p) {
        p--;
        if(p1!=NULL && p2!= NULL) {
            t = (struct Node * ) malloc(sizeof(struct Node));
            if(p1->exp==p2->exp) {
                num1=p1->exp;
                num2=p1->coeff+p2->coeff;
                p1 = p1 -> next;
                p2 = p2 -> next;
            }
            else if(p1->exp>p2->exp) {
                num1=p1->exp;
                num2=p1->coeff;
                p1 = p1 -> next;
            }
            else if(p1->exp<p2->exp) {
                num1=p2->exp;
                num2=p2->coeff;
                p2 = p2 -> next;
            }
            t->exp=num1;
            t->coeff=num2;

            t -> next = NULL;
            if (result == NULL) {
                result = last = t;
            } else {
                last -> next = t;
                last = t;
            }
        }
        if(p1!=NULL && p2==NULL){
            t = (struct Node * ) malloc(sizeof(struct Node));
            num1=p1->exp;
            num2=p1->coeff;
            p1 = p1 -> next;
            t->exp=num1;
            t->coeff=num2;

            t -> next = NULL;
            if (result == NULL) {
                result = last = t;
            } else {
                last -> next = t;
                last = t;
            }
        }
        if(p1==NULL && p2!=NULL){
            t = (struct Node * ) malloc(sizeof(struct Node));
            num1=p2->exp;
            num2=p2->coeff;
            p2 = p2 -> next;
            t->exp=num1;
            t->coeff=num2;

            t -> next = NULL;
            if (result == NULL) {
                result = last = t;
            } else {
                last -> next = t;
                last = t;
            }
        }
    }
    Display(result);
    result=NULL;
}

void sub(struct Node * p1, struct Node * p2) {
    struct Node * t, * last = NULL;
    int num1,num2;
    int p;
    if(p1->exp>p2->exp)
        p=p1->exp;
    else
        p=p2->exp;

    while (p) {
        p--;
        if(p1!=NULL && p2!= NULL) {
            t = (struct Node * ) malloc(sizeof(struct Node));
            if(p1->exp==p2->exp) {
                num1=p1->exp;
                num2=p1->coeff-p2->coeff;
                p1 = p1 -> next;
                p2 = p2 -> next;
            }
            else if(p1->exp>p2->exp) {
                num1=p1->exp;
                num2= - p1->coeff;
                p1 = p1 -> next;
            }
            else if(p1->exp<p2->exp) {
                num1=p2->exp;
                num2= - p2->coeff;
                p2 = p2 -> next;
            }
            t->exp=num1;
            t->coeff=num2;

            t -> next = NULL;
            if (result == NULL) {
                result = last = t;
            } else {
                last -> next = t;
                last = t;
            }
        }
        if(p1!=NULL && p2==NULL){
            t = (struct Node * ) malloc(sizeof(struct Node));
            num1=p1->exp;
            num2=p1->coeff;
            p1 = p1 -> next;
            t->exp=num1;
            t->coeff=num2;

            t -> next = NULL;
            if (result == NULL) {
                result = last = t;
            } else {
                last -> next = t;
                last = t;
            }
        }
        if(p1==NULL && p2!=NULL){
            t = (struct Node * ) malloc(sizeof(struct Node));
            num1=p2->exp;
            num2= - p2->coeff;
            p2 = p2 -> next;
            t->exp=num1;
            t->coeff=num2;

            t -> next = NULL;
            if (result == NULL) {
                result = last = t;
            } else {
                last -> next = t;
                last = t;
            }
        }
    }
    Display(result);
    result=NULL;
}


int main() {
    int x;
    printf("enter first polynomial:\n");
    create1();
    Display(poly1);
    create2();
    Display(poly2);
    add(poly1,poly2);
    printf("\n");
    sub(poly1,poly2);
    printf("\n");
    //mul(poly1,poly2);
    //printf("Enter value of x: ");
    //  scanf("%d", &x);

    // printf("%ld\n", Eval(poly, x));
    return 0;
}