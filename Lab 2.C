sparse matrix. 
#include<stdio.h> 
#include<conio.h> 
#define MAX_TERMS 101 
int k; 
typedef struct 
{
    int row,col,val;
}
TERM;
//FUNCTION TO READ SPARSE MATRIX AS A TRIPLE 
void read_sparse_matrix(TERM a[],int m,int n) 
{
    int i,j,item;
    a[0].row=m;
    a[0].col=n;
    k=1;
    printf("Enter the elements\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&item);
            if(item==0)
                continue;
            a[k].row=i;
            a[k].col=j;
            a[k].val=item;
            printf("Non zero element is stored in location a[%d].val=%d\n",k,a[k].val);
            k++;
        }
    }
    a[0].val=k-1;
}

void print_sparse_matrix(TERM a[])
{
    
    int p;
    printf("Non zero elements are present in the following location \n");
    for(p=1;p<k;p++)
        printf("row=%d col=%d val=%d\n",a[p].row,a[p].col,a[p].val);
}
//FUNCTION TO SEARCH FOR AN ITEM IN SPARSE MATRIX
void search(TERM a[],int item) 
{
    int i,j;
    for(i=0;i<k;i++)
    {
        if(item==a[i].val)
        {
            printf("Search is successful, Element found at pos %d\n",i);
            getch();
            exit(0);
        }
        
    }
    printf("Search is unsuccessful\n");
}

void main()
{
    
    int m,n,item;
    TERM a[MAX_TERMS];
    clrscr();
    printf("Enter the number of Rows & Columns\n");
    scanf("%d %d",&m,&n);
    read_sparse_matrix(a,m,n);
    print_sparse_matrix(a);
    printf("Enter the element to be searched\n");
    scanf("%d",&item);
    search(a,item);
    getch();
    
} 
