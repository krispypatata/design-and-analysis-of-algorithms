/***
UPDATE 6 Nov 2024: used this to test genisort
Usage:
gcc genisortPermutation.c
./a.out 5
./a.out 4

Testing Sir Eli's Leapfrogging Samplesort using 
permutations of 1 to N (c/o Sir Carino's template code)
gcc lfs.c && ./a.out 4

Leapfrogging Samplesort Code Reference:
EA. Albacea. 2012. Average-case analysis of Leapfrogging samplesort, Phil Sci Letters v5(1) 14-16.
https://philsciletters.net/2012/2012n1.5p3.pdf
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void LFSamplesort(int A[], int first, int last);
void Leapfrog(int A[], int s1, int ss, int u);

void LFSamplesort(int A[], int first, int last)
{
  int s;
  if (last > first) {
    s = 1;
    while (s <= (last-first-s)) {
      Leapfrog(A, first, first+s-1, first+s+s);
      s += (s+1);
    }
    Leapfrog(A, first, first+s-1, last);
  }
}

void Leapfrog(int A[], int s1, int ss, int u)
{
  int i,j,k, sm, v,t;
  if (s1 > ss) LFSamplesort(A, ss+1, u);
  else if (u > ss) {
    sm = (s1+ss) / 2;
    /* Partition */
    v = A[sm];
    j = ss;
    for(i=ss+1; i <= u; i++) {
      if (A[i] < v) {
        j++;
        t = A[j];
        A[j] = A[i];
        A[i] = t;
      }
    }
    /* Move Sample */
    if (j > ss) {
      for (k=j, i=ss; i >= sm; k--, i--) {
        t = A[i];
        A[i] = A[k];
        A[k] = t;
      }
    }
    Leapfrog(A, s1, sm-1,sm+j-ss-1);
    Leapfrog(A, sm+j-ss+1, j, u);
  }
}

void printA(int a[], int n){
  int i;
  for(i=0;i<n;i++)
    printf("%2i ",a[i]);
  printf("\n");
}


void swap(int *a, int *b){
    int temp=*a; *a=*b; *b=temp;
}

void init(int a[], int n){
    int i;

    for(i=0;i<n;i++)
        a[i]=i+1;

    for(i=0;i<n;i++)
        swap(&a[i], &a[rand()%n]);
}

void view(int a[], int n){
    int i;

    for(i=0;i<n;i++)
        printf("%3i ",a[i]);
    printf("\n");

}


void isort(int a[], int n){
    int i,j;

    for(i=1;i<n;i++)
        for(j=i;j>0;j--)
            if(a[j-1]>a[j])
                swap(&a[j-1],&a[j]);
            else break;

}

int cmpint(const void *p1, const void *p2){
    return ((*((int *)p1)) - (*((int *)p2)) > 0 );
}


void genswap(const void *p1, const void *p2, int size){
    void *ptemp=(void *)malloc(size);
    memcpy(ptemp,(void *)p1,size);
    memcpy((void *)p1,(void *)p2,size);
    memcpy((void *)p2,ptemp,size);
    free(ptemp);
}

void genisort(void *base, int n, int size, int (*cmp)(const void *, const void *)){
    int i,j;

    for(i=1;i<n;i++)
        for(j=i;j>0;j--)
	     if(cmp(base+((j-1)*size),base+(j*size)))
                 genswap(base+((j-1)*size),base+(j*size),size);
             else break;
}

void genbsort(void *base, int n, int size, int (*cmp)(const void *, const void *)){
    int i,j;

    for(i=1;i<n;i++)
        for(j=i;j>0;j--)
	     if(cmp(base+((j-1)*size),base+(j*size)))
                 genswap(base+((j-1)*size),base+(j*size),size);
             else break;
}


int main(int argc, char *argv[]){
  int n=atoi(argv[1]);
  int a[n];
  
  //Sir Carino's Template code for permutation
  int option[n+2][n+2];
  int nopts[n+2];
  int move, start;
  int i,c;
  
  move=start=0;
  nopts[start]=1;
  option[start][nopts[start]]=0;
  
  while(nopts[start]>0){
    if(nopts[move]>0) {
	  nopts[++move]=0;
	  if(move==n+1){
	    for(i=0;i<n;i++)
		  a[i]=option[i+1][nopts[i+1]];
	    printA(a,n);
		//LFSamplesort(a,0,n-1); //call Sir Eli's LFS
		genisort(a, n, sizeof(int), cmpint);
		//isort(a,n);
		//printA(a,n);
	    for(i=0;i<n-1;i++)
		  if(a[i]>a[i+1]) break;
        if(i<n-1){
		  printf("sorting error: ");
          printA(a,n);			
		  exit(1);
		}
	  }
	  else {
		for(c=n;c>=1;c--){
		  for(i=move-1;i>=1;i--)
		    if(option[i][nopts[i]]==c) break;
		  if(!(i>=1)) option[move][++nopts[move]]=c;
		}
	  }
		  
	}
	else nopts[--move]--; //backtrack
  }
}
