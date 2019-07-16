//Queue
#include<stdio.h> 
#include<conio.h> 
#define QSIZE 5 
int choice,item,f,r,q[10]; 
void insert_rear() 
{
    if(r==QSIZE-1)
    {
        printf("Q full\n");
        return;
    }
    r=r+1;
    q[r]=item; 
}
void delete_front()
{
    if(f>r)
    {
        printf("Q underflow\n");
        return;
    }
    printf("Element Deleted is %d\n",q[f]);
    f++; 
    if(f>r) 
    {   f=0;
        r=-1;
    }
    
}
void display()
{
    int i;
    if(f>r) 
    {
        printf("Q is empty\n");
        return;
    }
    printf("contents of the queue\n");
    for(i=f;i<=r;i++) 
        printf("%d\n",q[i]);
}

void main()
{
    f=0; 
    r=-1; 
    clrscr(); 
    for(;;) 
    {
        printf("1:INSERT 2:DELETE 3;DISPLAY 4: EXIT\n");
        scanf("%d",&choice);
        switch(choice) 
        {
            case 1 :
                printf("enter the item\n");
                scanf("%d",&item);
                insert_rear(item,q,&r);
                break;
            case 2 :
                delete_front(q,&f,&r);
                break;
            case 3 :
                display(q,f,r);
                break;
            default:
                exit(0);
        }
        
    }
    
}
