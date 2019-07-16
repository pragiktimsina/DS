// BUCKET SORT PROGRAM 
#include<stdio.h> 
#define SIZE 100 

void bucketSort(int a[], int n)
{
    int i, j, k, buckets[SIZE]; 
    for(i = 0; i < SIZE; i++)
        buckets[i] = 0;
    for(i = 0; i < n; ++i) 
        buckets[a[i]]++;
    for(j = 0; j < SIZE; j++)
    {
        for(k = buckets[j]; k > 0; k--)
            a[i++] = j;
    }
}

void main()
{ 
    int a[100], i, n; 
    clrscr(); 
    printf("Enter the size of array : "); 
    scanf("%d", &n); 
    printf("enter array elements\n"); 
    for(i=0;i<n;i++) 
        scanf("%d",&a[i]);
    printf("Before sorting:\n"); 
    for(i = 0; i < n; ++i) 
        printf("%d ", a[i]); 
    bucketSort(a, n); 
    printf("\n\nAfter sorting:\n"); 
    for(i = 0; i < n; ++i) 
        printf("%d ", a[i]);
    getch(); 
} 
