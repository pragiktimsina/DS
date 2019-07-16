//stack
#include<stdio.h>
#include<conio.h>
#define STACK_SIZE 5
int top,s[10],item;
void push()
{
    if(top==STACK_SIZE-1)
    {
        printf("stack full\n");
        return;
    }
    top=top+1;
    s[top]=item;
}

int pop()
{
    int item_deleted;
    if(top==-1)
        return 0;
    item_deleted=s[top--];
    return item_deleted;
}

void display()
{
    int i;
    if(top==-1)
    {
        printf("stack is empty\n");
        return;
    }
    
    printf("contents of the stack\n");
    for(i=top;i>=0;i--)
        printf("%d\n",s[i]);
}
void main()
{
    int choice;
    top=-1;
    clrscr();
    for(;;)
    {
        printf("1:PUSH 2:POP 3:DISPLAY 4:EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
                printf("enter the item\n");
                scanf("%d",&item);
                push();
                break;
            case 2 :
                item=pop();
                if(item==-1)
                    printf("stack is empty\n");
                else
                    printf("item deleted =%d\n",item);
                break;
            case 3 :
                display();
                break;
                
            default:exit(0);
        }
        
    }
    
}
