#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        printf("Thread %d\n", omp_get_thread_num());
    }
    return 0;
}


// gcc -fopenmp omp_check.c -o omp_check
// gcc -fopenmp -dM -E - < /dev/null | grep -i openmp

