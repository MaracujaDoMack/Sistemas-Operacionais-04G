#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int **mat;
int *vet;
int *result;
int lMat, cMat, v;

// função da thread - calcula o valor de cada linha da matriz pelo vetor e insere no vetor resultado
void *thread_function(void *arg){
    
    int thread_index = *((int *)arg);
    int total = 0;
    
    for(int i = 0; i < v; i++){
        total += (mat[thread_index][i] * vet[i]);
    }
    
    result[thread_index] = total;
    
}

int main()
{

    // alocando memória para a matriz e os vetores
  
    printf("Insira as dimensões da matriz (Linhas e Colunas): ");
    scanf("%d %d", &lMat, &cMat);
    
    printf("Insira a quantidade de elementos no vetor: ");
    scanf("%d", &v);
    
    if(cMat != v){
        printf("\nErro! Número de colunas da matriz é diferente do número de elementos do vetor!\n");
        return 1;
    }
    
    mat = (int **)malloc(sizeof(int *) * lMat);
    
    for (int i = 0; i < lMat; i++) {
        mat[i] = (int *)malloc(sizeof(int) * cMat);
        if (mat[i] == NULL) {
            printf("\nErro ao alocar memória!\n");
            for (int j = 0; j < i; j++) {
                free(mat[j]);
            }
            free(mat);
            return 1;
        }
    }
    
    vet = (int *)malloc(sizeof(int) * v);
    
    result = (int *)malloc(sizeof(int) * lMat);
    
    for (int i = 0; i < lMat; i++) {
        for (int j = 0; j < cMat; j++) {
            printf("Insira o valor da linha %d e coluna %d da matriz: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    
    for (int i = 0; i < v; i++) {
        printf("Insira o elemento na posição %d do vetor: ", i);
        scanf("%d", &vet[i]);
    }

    // threads
  
    pthread_t *threads = malloc(sizeof(pthread_t) * lMat);
    int *thread_args = malloc(sizeof(int) * lMat);
  
    for(int i = 0; i < lMat; i++){
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, thread_function, (void *)&thread_args[i]);
    }
    
    for (int i = 0; i < lMat; i++) {
        pthread_join(threads[i], NULL);
    }

    // mostrando o resultado da multiplicação
    printf("\nVetor resultante da multiplicação: ");
    for(int i = 0; i < lMat; i++){
        printf("%d ", result[i]);
    }
    printf("\n");

    // liberando memória
    
    free(threads);
    free(thread_args);
    
    for (int i = 0; i < lMat; i++) {
        free(mat[i]);
    }
    
    free(mat);
    free(vet);
    free(result);
    
    return 0;
}
