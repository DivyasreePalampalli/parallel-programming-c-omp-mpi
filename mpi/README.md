
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


MPI_Send(void *message, int size, MPI_INT, int process, 0, MPI_COMM_WORLD). This function sends the message in the memory pointed to by message to the process whose rank is given in process. The message is an array of integers, where the number of integers is given in size.
MPI_Recv(void *message, int size, MPI_INT, int process, 0, MPI_COMM_WORLD, 0). This function receives the message from the process whose rank is given in process. The received message is placed into the memory pointed to by message. The message is an array of integers, where the number of integers is given in size.

It is possible to send messages of other data types, e.g.
MPI_INT - the message is a single integer, or an array of integers
MPI_FLOAT - the message is a single float or an array of floats
MPI_DOUBLE - the message is a single double or an array of doubles

```

##  Run MPI Program
```
mpirun -np 4 program # this will copies program to 4 process and runs parallely

```