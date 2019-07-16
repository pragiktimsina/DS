//Tower of Hanoii
#include<stdio.h>
#include<conio.h>
void tower(int n,char src,char temp,char des)
{
    if(n==1)
    {
        printf("move disc %d from %c to %c\n",n,src,des);
        return;
    }
    tower(n-1,src,des,temp);
    printf("move disc %d from %c to %c\n",n,src,des);
    tower(n-1,temp,src,des);
}

void main()
{
    int n;
    clrscr();
    printf("Enter the number of discs\n");
    scanf("%d",&n);
    tower(n,'S','T','D');
    getch();
}
