 #include <mpi.h>
 #include <stdio.h>
 int main(int argc, char *argv[]) {
    int rank, size;
    int number;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (size < 2) {
        if (rank == 0)
            printf("Please run with at least 2 processes.\n");
        MPI_Finalize();
        return 0;
    }
    if (rank == 0) {
        number = 100;
        printf("Process %d sending number %d to process 1\n", rank, number);
        MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    } else if (rank == 1) {
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process %d received number %d from process 0\n", rank, number);
    }
    MPI_Finalize();
    return 0;
 }
 OUTPUT:
 secabiet@secabiet-Vostro-3470:~$ mpicc prg5.c -o prg5
 secabiet@secabiet-Vostro-3470:~$ mpirun -np 2 ./prg5
 Process 0 sending number 100 to process 1
 Process 1 received number 100 from process 0
