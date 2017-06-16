#include<stdio.h>
void insertion_sort(int x[],int n);
int main()
{
	int a[5]={3,5,1,4,2};
	insertion_sort(a,5);
	int i;
	for(i=0;i<5;i++)
		printf("%d ",a[i]);
	return 0;
}
void insertion_sort(int x[],int n){
	int i,j,key;
	for(j=n-2;j>=0;j--){
		key=x[j];
		i=j+1;
		while(i<n&&x[i]<key){
			x[i-1]=x[i];
			i++;
		}
		x[i-1]=key;
	}
}
