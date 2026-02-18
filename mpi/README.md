
---

# MPI – Distributed Memory Parallel Programming

MPI (Message Passing Interface) is used for parallel programming
across multiple processes.

---

##  Compile MPI Program

```bash
mpicc program.c -o program


MPI_Init / MPI::Init - Used to initialise MPI.
MPI_Finalize - Used to close down MPI.
MPI_Comm_size / MPI::COMM_WORLD.Get_size() - used to get the number of processes in the team
MPI_Comm_rank / MPI::COMM_WORLD.Get_rank() - used to get the ID number (rank) of a process in the team.

```

##  Run MPI Program
```
mpirun -np 4 program # this will copies program to 4 process and runs parallely

```