#include <stdio.h>
#include <stdlib.h>

int its_podpos(int n, const int *M){
        if(M[n-3] < M[n-2] && M[n-2] < M[n-1]) {
                printf("%i %i %i\n", M[n-3], M[n-2], M[n-1]);
                return 1;
        }
        else return 0;
}

int recur(const int *M, int n)
{
        if(n>=3 && its_podpos(n, M)) {
                printf("%i\n", n);
                return 1;
        }
        else{
                if(n>=3){
                        return recur(M, n-1);
                }
                return 0;
        }
}

int main()
{
        int N;
        while (scanf("%d", &N) != 1 || N<3){
                while (getchar() != '\n');
                printf("Введите N >= 3\n");
        }

        int *M = (int*) malloc(N * sizeof(int));
        for (int i=0; i<N; i++)
        {
                printf("a[%d] = ", i);
                while(scanf("%d", &M[i]) != 1){
                        while (getchar() != '\n');
                        printf("Введите число\n");
                }
        }

        if (recur(M, N)){
                printf("True\n");
        }
        else{
                printf("False\n");
        }
        free(M);
}
