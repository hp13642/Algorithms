/*
	Name: Selection Sort
	Copyright: 
	Author: Hemant Pandey
	Date: 16/08/16 21:25
	Description: Comp:O(n^2) and Swap:O(n)
*/

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
void Selection_Sort(int a[],int n);
int main()
{
	int *a;
	a=(int *)malloc(sizeof(int)*MAXSIZE);
	int i;
	for(i=0;i<MAXSIZE;i++)
		scanf("%d",&a[i]);
	Selection_Sort(a,MAXSIZE);
	for(i=0;i<MAXSIZE;i++)
		printf("%d ",a[i]);
	return 0;
}

// Selection Sort logic
//Maximum element put at end
void Selection_Sort(int a[],int n){
	int i,j,m,temp;
	for(i=0;i<n;i++){
		m=i;
		for(j=0;j<n-i;j++){
			if(a[m]<=a[j])
				m=j;
		}
		temp=a[n-1-i];
		a[n-1-i]=a[m];
		a[m]=temp;
	}
}


//Hackerearth code of selection sorting
//Minimum element put at start
void selection_sort (int A[ ], int n) {
        // temporary variable to store the position of minimum element

        int minimum;        
        // reduces the effective size of the array by one in  each iteration.

        for(int i = 0; i < n-1 ; i++)  {

           // assuming the first element to be the minimum of the unsorted array .
             minimum = i ;

          // gives the effective size of the unsorted  array .

            for(int j = i+1; j < n ; j++ ) {
                if(A[ j ] < A[ minimum ])  {                //finds the minimum element
                minimum = j ;
                }
             }
          // putting minimum element on its proper position.
          swap ( A[ minimum ], A[ i ]) ; 
        }
   }
