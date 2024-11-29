#include <stdio.h>

int main()
{
    int N = 4;

    int nopts[N + 2];         // Array of top of stacks
    int option[N + 2][N + 2]; // Array of stack of options
    int start, move, i, candidate;

    move = start = 0;
    nopts[move] = 1;

    while (nopts[start] > 0)
    {                        // While dummy stack is not empty
        if (nopts[move] > 0) // else backtrack
        {
            nopts[++move] = 0; // initialize new move

            if (move <= N)
            { // Find candidates (No need to find duplicates)
                // Consider N down to 1 as valid candidates

                int start_candidate = (move == 1) ? 1 : option[move - 1][nopts[move - 1]] + 1;

                for (candidate = N; candidate >= start_candidate; candidate--)
                {
                    option[move][++nopts[move]] = candidate;
                }
            }
        }
        else
        {
            if (move > 1)
            { // Solution found!
                for (i = 1; i < move; i++)
                {
                    printf("%d ", option[i][nopts[i]]);
                }
                printf("\n");
            }

            nopts[--move]--;
        }
    }
}