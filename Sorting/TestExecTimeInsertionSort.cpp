/*
	Name: Find time taken in execution of a function
	Copyright: 
	Author: Hemant Pandey
	Date: 07/09/16 15:31
	Description: 
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>
void Insertion_Sort(int x[],int n);
int main()
{
	clock_t start, end;
     double cpu_time_used;
     int x[1000],i,n=1000;
     for(i=0;i<100;i++)
     	x[i]=rand()%1000;
     start = clock();
     Insertion_Sort(x,1000);
     end = clock();
     cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	 printf("Time used:%f",cpu_time_used);
	 return 0;	
}

void Insertion_Sort(int x[],int n){
	int i,j,key;
	for(j=1;j<n;j++){
		key=x[j];
		i=j-1;
		while(i>=0&&x[i]>key){
			x[i+1]=x[i];
			i--;
		}
		x[i+1]=key;
	}
}
     
