/*
	Name: Find element having Rank in an given array using median of median
	Copyright: 
	Author: Hemant Pandey
	Date: 06/09/16 22:35
	Description: given an array and it's lower index and upper index
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXSIZE 5
void Bubble_Sort(int a[],int i,int j);
int findRank(int x[],int i,int j,int r);
int RPivot(int x[],int i,int j);
int Partition(int a[],int l,int r);
int main()
{
	int a[MAXSIZE];
	int i;
	for(i=0;i<MAXSIZE;i++)
		scanf("%d",&a[i]);
	int rank;
	scanf("%d",&rank);
	int element;
	element=findRank(a,0,MAXSIZE-1,rank);
	printf("%d",element);
	return 0;
	
}

int findRank(int x[],int i,int j,int r){
	int t,p=RPivot(x,i,j);
	t=x[p];							// in this aprtition function p is index of pivot lelement
	x[p]=x[j];
	x[j]=t;	
	int k=Partition(x,i,j);
	//printf("%d  %d\n",p,k);
	if(r==j-k+1)
		return x[k];
	else if(r<j-k+1)
		return findRank(x,k+1,j,r);		
	else
		return findRank(x,i,k,r-j+k);
			
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
// fix no of element in each group is 5
int RPivot(int x[],int i,int j){
	int y=0,l,med;
	if(i+4>=j){
		Bubble_Sort(x,i,j);
		return (j+i)/2;
	}
	
	for(l=0;l<=j;l+=5){
		Bubble_Sort(x,l,l+4);
		med=l+2;
		swap(&x[med],&x[y]);
		y++;
	}
	int t;
	t=j%5;
	if(t>2){
		 Bubble_Sort(x,j-t,j-1);
		 med=j-2;
		 swap(&x[med],&x[y]);
		 //y++;
	}
	return RPivot(x,0,y);
}
void swap(int *x,int *y){
	int t;
	t=*x;
	*x=*y;
	*y=t;
}

void Bubble_Sort(int a[],int i,int j){
		int temp,k,l;
		for(k=i;k<=j;k++){
			for(l=i;l<j;l++){
				if(a[l]>a[l+1]){
					temp=a[l+1];
					a[l+1]=a[l];
					a[l]=temp;
				}
			}
		}
		
}
