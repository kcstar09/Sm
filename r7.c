 #include <mpi.h>
 #include <stdio.h>
 int main(int argc, char *argv[]) {
    int rank, size;
    int number;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0) {
        number = 50;
        printf("Process %d broadcasting number %d to all other processes.\n", rank, number);
    }
    MPI_Bcast(&number, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Process %d received number %d\n", rank, number);
    MPI_Finalize();
    return 0;
 }
 OUTPUT:
 secabiet@secabiet-Vostro-3470:~$ mpicc prg7.c -o prg7
 secabiet@secabiet-Vostro-3470:~$ mpirun -np 4 ./prg7
 Process 0 broadcasting number 50 to all other processes.
 Process 0 received number 50
 Process 1 received number 50
 Process 2 received number 50
 Process 3 received number 50
