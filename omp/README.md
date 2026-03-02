
---


# OpenMP – Shared Memory Parallel Programming

OpenMP is used for parallel programming on shared memory systems
using threads.

---

## Compile with OpenMP

```bash
gcc -fopenmp program.c -o program

parallel : Used to create a parallel block of code which will be executed by a team of threads
sections : Used to specify different sections of the code that can be run in parallel by different threads.
for (C/C++), do (Fortran) : Used to specify loops where different iterations of the loop are performed by different threads.
critical : Used to specify a block of code that can only be run by one thread at a time.
reduction : Used to combine (reduce) the results of several local calculations into a single result


omp_get_num_threads() : Returns the number of threads in the OpenMP thread team.
omp_get_thread_num() : Returns the identifying number of the thread in the team.
private(nthreads, thread_id) is added to specify that each thread should have its own copy of the nthreads and thread_id variables.

