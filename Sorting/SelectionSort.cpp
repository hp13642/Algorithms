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
void Selection_Sort(int a[],int n){
	int i,j,m,temp;
	for(i=0;i<n;i++){
		m=0;
		for(j=0;j<n-i;j++){
			if(a[m]<=a[j])
				m=j;
		}
		temp=a[n-1-i];
		a[n-1-i]=a[m];
		a[m]=temp;
	}
}
