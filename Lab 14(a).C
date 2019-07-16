//FUNCTION TO SEARCH AN ELEMENT USING BINARY SEARCH LOGIC

#include<stdio.h>
#include<conio.h>

int search(int key,int a[],int low,int high)
{
    int mid;
    if(low>high)
        return -1;
    mid=(low+high)/2;
    if(key==a[mid])
        return mid;
    if(key<a[mid])
        search(key,a,low,mid-1);
    else
        search(key,a,mid+1,high);
}

void main()

{
    
    int n,i,a[20],key,pos;
    clrscr();
    printf("enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the key ele to be searched\n"); scanf("%d",&key);
    pos=search(key,a,0,n-1);
    if(pos==-1)
        printf("Key ele not found\n");
    else
        printf("Element found at pos %d\n",pos);
    
    getch();
}
