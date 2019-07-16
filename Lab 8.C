//C PROGRAM TO CREATE A LIST AND TO DISPLAY THE CONTENTS OF THE LIST USING STACKS

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
NODE insertfront(int item,NODE first)
{
    NODE temp;
    temp=getnode(); 
    temp->info=item; 
    temp->link=first; 
    return temp; 
}

NODE deletefront(NODE first)
{
    NODE temp;
    if(first==NULL) 
    { printf("list is empty cannot delete\n"); 
        return first; 
    } temp=first;
    temp=temp->link; 
    printf("item deleted=%d\n",first->info); 
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
        printf("1:InsertFront 2:DeleteFront 3:Display 4:Quit\n");
        printf("Enter ur choice\n");
        scanf("%d",&choice);
        switch(choice) 
        {
            case 1:
                printf("Enter the item to be inserted\n");
                scanf("%d",&item);
                first=insertfront(item,first);
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
