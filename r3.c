 #include <stdio.h>
 #include <omp.h>
 int fib(int n) {
    int x, y;
    if (n < 2)
        return n;
    #pragma omp task shared(x)
    x = fib(n - 1);
    #pragma omp task shared(y)
    y = fib(n - 2);
    #pragma omp taskwait
    return x + y;
 }
 int main() {
    int n;
    printf("Enter number of Fibonacci terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series:\n");
    for (int i = 0; i < n; i++) {
        int result;
        #pragma omp parallel
        {
            #pragma omp single
            {
                result = fib(i);
            }
        }
        printf("%d ", result);
    }

    printf("\n");
    return 0;
 }
 OUTPUT:
 secabiet@secabiet-Vostro-3470:~$ gcc -fopenmp prg3.c -o prg3
 secabiet@secabiet-Vostro-3470:~$ export OMP_NUM_THREADS=4 && ./prg3
 Enter number of Fibonacci terms: 6
 Fibonacci Series:
 0 1 1 2 3 5
