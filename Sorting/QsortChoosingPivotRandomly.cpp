/*
	Name: Quick Sort implementation choosing pivot element randomely
	Copyright: 
	Author: Hemant Pandey
	Date: 18/08/16 00:11
	Description: average case running time O(n log n) and faster than merge sort for general input
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXSIZE 5
void Quick_Sort(int *,int,int);
int Partition(int *,int,int);
int Partition2(int a[],int l,int r,int p);
int Pivot(int *,int,int);
int main()
{
	int *a;
	a=(int *)malloc(sizeof(int)*MAXSIZE);
	int i;
	for(i=0;i<MAXSIZE;i++)
		scanf("%d",&a[i]);
	Quick_Sort(a,0,MAXSIZE-1);
	for(i=0;i<MAXSIZE;i++)
		printf("%d ",a[i]);
	return 0;
}
void Quick_Sort(int a[],int l,int r){
if(l<r){
		int p,k,t;
	p=Pivot(a,l,r);
	t=a[p];							// in this aprtition function p is index of pivot lelement
	a[p]=a[r];
	a[r]=t;	
	k=Partition(a,l,r);
	Quick_Sort(a,l,k);
	Quick_Sort(a,k+1,r);
}
}

int Partition(int a[],int l,int r){
	int i,j,x,t;
	i=l-1;
	x=a[r];
	for(j=l;j<r;j++){
		if(a[j]<=x){
			i++;
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	t=a[i+1];
	a[i+1]=a[r];
	a[r]=t;
	return ++i;
}

int Pivot(int a[],int l,int r){
	
       return l+rand()/(RAND_MAX/(r-l+1)+1);	
}


int Partition2(int a[],int l,int r,int p){
	int i=l,j=r,t;			// in this function p is element that is choosen for pivot
	while(i<=j){
		while(a[i]<=p)
			i++;
		while(a[j]>p)
			j--;
		if(i<j){
			t=a[j];
			a[j]=a[i];
			a[i]=t;
		}
		i++;
		j--;
	}
	return j;
}
