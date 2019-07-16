//Program to add two polynomials
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<alloc.h>
#include<math.h>
//STRUCTURE DEFINITION
struct node
{
    int coeff;
    int expon;
    struct node *link;
};
typedef struct node *NODE;
//CREATING NEW NODE USING DYNAMIC MEMORY ALLOCATION
NODE getnode()

{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("OUT OF MEMORY\n");
        getch();
        exit(0);
        
    }
    return x;
    
}
//FUNCTION TO INSERT NEW NODES i.e ADDING/ATTACHING TERMS TO POLYNOMIAL
NODE attach(int coeff,int expon,NODE head)
{
    NODE temp,cur;
    temp=getnode();
    temp->coeff=coeff;
    temp->expon=expon;
    cur=head->link;
    while(cur->link!=head)
        cur=cur->link;
    cur->link=temp;
    temp->link=head;
    return head;
}
//FUNCTION TO READ A POLYNOMIAL
NODE read_poly(NODE head)
{
    int i;
    int coeff,expon;
    printf("Enter co-efficient as -999 to end the polynomial\n");
    for(i=1;;i++)
    {
        printf("Enter %d terms\n",i);
        printf("Enter co-efficient\n");
        scanf("%d",&coeff);
        if(coeff==-999)
            break;
        printf("Enter power of x\n");
        scanf("%d",&expon);
        head=attach(coeff,expon,head);
    }
    return head;
}

//FUNCTION TO ADD 2 POLYNOMIALS
NODE add_poly(NODE h1,NODE h2,NODE h3)
{
    NODE a,b;
    int coeff,val;
    a=h1->link;
    b=h2->link;
    while(a!=h1 && b!=h2)
    {
        if(a->expon==b->expon)
            val=0;
        else if (a->expon>b->expon)
            val=1;
        else
            val=2;
        switch(val)
        {
            case 0:
                coeff=a->coeff+b->coeff;
                if(coeff!=0)
                    h3=attach(coeff,a->expon,h3);
                a=a->link;
                b=b->link;
                break;
            case 1:
                h3=attach(a->coeff,a->expon,h3);
                a=a->link;
                break;
            default:
                h3=attach(b->coeff,b->expon,h3);
                b=b->link;
                
        }
    }
    while(a!=h1)
        h3=attach(a->coeff,a->expon,h3); a=a->link;
    while(b!=h2)
        h3=attach(b->coeff,b->expon,h3); b=b->link;
    return h3;
}
//FUNCTION TO DISPLAY A POLYNOMIAL

void display(NODE head)
{
    NODE temp;
    if(head->link==head)
    {
        printf("POLYNOMIAL DOES NOT EXIST\n");
        return;
    }
    temp=head->link;
    while(temp!=head)
    {
        if(temp->coeff<0)
            printf("%dx^%d",temp->coeff,temp->expon);
        else
            printf("+%dx^%d",temp->coeff,temp->expon);
        temp=temp->link;
    }
    
}
//MAIN FUNCTION

void main()
{
    NODE h1,h2,h3;
    int choice;
    clrscr();
    h1=getnode();
    h2=getnode();
    h3=getnode();
    h1->link=h1;
    h2->link=h2;
    h3->link=h3;
    printf("Enter the 1st POLYNOMIAL\n");
    h1=read_poly(h1);
    printf("Enter the 2nd POLYNOMIAL\n");
    h2=read_poly(h2);
    h3=add_poly(h1,h2,h3);
    printf("The 1st POLYNOMIAL is \n");
    display(h1);
    printf("\nThe 2ND POLYNOMIAL is \n");
    display(h2);
    printf("\nThe 3rd POLYNOMIAL is \n");
    display(h3);
    getch();
}
