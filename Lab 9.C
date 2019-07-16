//C PROGRAM TO CREATE A LIST AND TO DISPLAY THE CONTENTS OF THE LIST USING QUEUES
#include<stdio.h> 
#include<conio.h> 
#include<process.h> 
#include<alloc.h> 
struct node

{
    int info;
    struct node *link; 
};

typedef struct node *NODE;

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

NODE insertrear(int item,NODE first)
{
    NODE temp;
    NODE cur; 
    temp=getnode(); 
    temp->info=item; 
    temp->link=NULL; 
    if(first==NULL) 
        return temp;
    cur=first; 
    while(cur->link!=NULL)
        cur=cur->link;
    cur->link=temp;
    
    return first;
}

NODE deletefront(NODE first) 
{
    NODE temp;
    if(first==NULL) 
    {
        printf("list is empty cannot delete\n");
        return first;
    }
    
    temp=first;
    temp=temp->link; 
    printf("Item deleted=%d\n",first->info);
    free(first); 
    first=NULL; 
    return temp;
}

void display(NODE first)
{
    NODE temp;
    if(first==NULL) 
    {
        printf("List is Empty\n");
        return;
    }
    printf("CONTENTS OF THE SINGLY LINKED LIST\n");
    temp=first;
    while(temp!=NULL) 
    {
        printf("%d\n",temp->info);
        temp=temp->link;
    }
    printf("\n");
}

void main()
{
    NODE first=NULL;
    int choice,item; 
    clrscr(); 
    for(;;) 
    {
        printf("1:Insert Rear 2:Delete Front 3:Display 4:Quit\n");
        printf("Enter ur choice\n"); 
        scanf("%d",&choice); 
        switch(choice) 
        {
                
            case 1:
                printf("Enter the item to be inserted\n");
                scanf("%d",&item);
                first=insertrear(item,first);
                break; 
            case 2:
                first=deletefront(first);
                break;
            case 3:
                display(first);
                break; 
            default:
                exit(0);
        }
        
    }
    
}
