//142 Lec codes implementation of Shell Sort
//2024-10-08
#include<stdio.h>

void swap(int *a, int *b){
  int temp=*a; *a=*b; *b=temp;
}

void shsort(int a[], int n){
  int i,j,d;

  for(d=n/2;d>0;d/=2)
  for(i=d;i<n;i++)
    for(j=i;j>d-1;j-=d)
      if(a[j]<a[j-d])
	swap(&a[j],&a[j-d]);
      else
	break;
}

void printArray(int a[], int n){
  for(int i=0;i<n;i++)
    printf("%2i ",a[i]);
  printf("\n");
}

int main(){
  int n=5;
  int a[n];

  for(int i=0;i<n;i++)
    a[i]=n-i;

  printArray(a,n);
  shsort(a,n);
  printArray(a,n);

  return(0);
}
