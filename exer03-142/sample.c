#include <stdio.h>
#include <time.h>

void main()
{

    // int n = 400000; // might be changed depending on the machine
    // int n = 100000*1; // linear
    int n = 100*8; // quadratic
    int a[n], i, j;

    // time_t t1, t2;

    clock_t t1, t2;
    double t;
    t1 = clock();

    // time(&t1); //for time_t

    // linear algorithm
    // for (i = 0; i < n; i++)
    //     printf("%i\n", i + 1);

    // quadratic algorithm
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            printf("%i\n", i + 1);

    // time(&t2);
    t2 = clock();
    t = (double)(t2 - t1) / (double)CLOCKS_PER_SEC;
    printf("\n\ntime elapsed: %0.6f seconds\n", t);
}