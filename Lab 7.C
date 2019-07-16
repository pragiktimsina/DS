//Circular queue

#include<stdio.h> 
#include<process.h> 
#define QSIZE 3
int item,f,r,count,q[20]; 
void insert_rear() 
{
    if(count==QSIZE)
        
    { printf("Element cannot be inserted queue overflow\n");
        return;
    }
    r=(r+1)%QSIZE;
    q[r]=item;
    count=count+1;
}

void delete_front()
{
    if(count==0)
    {
        printf("queue underflow\n");
        return;
    }
    printf("deleted ele =%d\n",q[f]);
    f=(f+1)%QSIZE;
    count=count-1;
}

void display()
{
    int i;
    int temp=f; 
    if(count==0) 
    {
        printf("Q is empty\n");
        return;
    }
    printf("contents of queue\n");
    for(i=1;i<=count;i++) 
    {
        printf("value of front==%d and q[%d]=%d\n",temp,temp,q[temp]);
        temp=(temp+1)%QSIZE;
    }
    
}

void main()
{
    int choice;
    clrscr();
    f=0;
    r=-1;
    count=0; 
    for(;;) 
    {
        printf("1:Insert 2:Delete 3: Display 4:exit\n");
        printf("enter the choice\n"); 
        scanf("%d",&choice); 
        switch(choice) 
        {
            case 1:
                printf("enter the item to be inserted\n");
                scanf("%d",&item);
                insert_rear();
                break;
            case 2:
                delete_front();
                break;
                
            case 3:
                display();
                break;
                
            default:
                exit(0);
        }
        
    }
    
}
