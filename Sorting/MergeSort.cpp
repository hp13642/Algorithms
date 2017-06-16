/*
	Name: Merge Sort
	Copyright: 
	Author: 
	Date: 16/08/16 21:39
	Description: Running Time:O(nlogn)
*/
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5
void Merge_Sort(int a[],int l,int r);
void Merge(int a[],int l,int r,int k);
int main()
{
	int *a;
	a=(int *)malloc(sizeof(int)*MAXSIZE);
	int i;
	for(i=0;i<MAXSIZE;i++)
		scanf("%d",&a[i]);
	Merge_Sort(a,0,MAXSIZE-1);
	for(i=0;i<MAXSIZE;i++)
		printf("%d ",a[i]);
	return 0;
}

//Merge Sort logic
void Merge_Sort(int a[],int l,int r){
	if(l<r){
		int k=(l+r)/2;
		Merge_Sort(a,l,k);
		Merge_Sort(a,k+1,r);
		Merge(a,l,r,k);
	}
}

void Merge(int a[],int l,int r,int k){
	int *b;
	b=(int *)malloc(sizeof(int)*(r-l+1));
	int i=l,j=k+1,x=0;
	while(i<=k&&j<=r){
		if(a[i]<a[j])
			b[x++]=a[i++];
		else
			b[x++]=a[j++];
	}	
	while(i<=k)
		b[x++]=a[i++];
	while(j<=r)
		b[x++]=a[j++];
	i=l;
	x=0;
	while(i<=r)
		a[i++]=b[x++];
	free(b);
}
