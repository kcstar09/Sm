 #include <stdio.h>
 #include <omp.h>
 int main() {
    int n;
    printf("Enter number of iterations: ");
    scanf("%d", &n);
    int thread_start[100], thread_end[100];
    int i;
    for (i = 0; i < 100; i++) {
        thread_start[i] = -1;
        thread_end[i] = -1;
    }
    #pragma omp parallel for schedule(static,2)
    for (i = 0; i < n; i++) {
        int tid = omp_get_thread_num();
        if (thread_start[tid] == -1)
            thread_start[tid] = i;
        thread_end[tid] = i;
    }
    for (i = 0; i < 100; i++) {
        if (thread_start[i] != -1) {
            printf("Thread %d : Iterations %d -- %d\n", i, thread_start[i], thread_end[i]);
        }
    }
    return 0;
 }

 OUTPUT:
 secabiet@secabiet-Vostro-3470:~$ gcc -fopenmp prg2.c -o prg2
 secabiet@secabiet-Vostro-3470:~$ export OMP_NUM_THREADS=4 && ./prg2
 Enter number of iterations: 6
 Thread 0 : Iterations 0 -- 1
 Thread 1 : Iterations 2 -- 3
 Thread 2 : Iterations 4 -- 5
