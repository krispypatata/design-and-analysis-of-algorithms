#include <stdio.h>

int main() {
    int N = 4;

    int nopts[N + 2];         // array of top of stacks
    int option[N + 2][N + 2]; // array of stacks of options
    int start, move, i, candidate;

    move = start = 0;
    nopts[start] = 1;

    while (nopts[start] > 0) { // while dummy stack is not empty

        if (nopts[move] > 0) { // else backtrack
            nopts[++move] = 0; // initialize new move

            if (move > N) { // solution found!
                for (i = 1; i < move; i++) { // print solution
                    printf("%2i ", option[i][nopts[i]]);
                }
                printf("\n");
            }
            else { // find candidates
                // consider N down to 1 as valid candidates
                for (candidate = N; candidate >= 1; candidate--) {
                    for (i = move - 1; i >= 1; i--) { // check for duplicates
                        if (option[i][nopts[i]] == candidate) break;
                    }

                    if (!(i >= 1)) { // no duplicates found
                        option[move][++nopts[move]] = candidate; // push candidate
                    }
                }
            }
        }
        else {
            nopts[--move]--; // backtrack
        }
    }
}
