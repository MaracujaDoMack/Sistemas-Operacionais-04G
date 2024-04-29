# Lab 04

## Multiplicação Matriz-Vetor usando pthreads

Para esse problema, primeiramente, nós alocamos a memória para a matriz e o vetor a serem multiplicados, além do vetor resultante, então criamos um vetor de threads a partir da estrutura pthreads, o qual será responsável por guardar todas as threads que criaremos em um for loop com o tamanho da quantidade de linhas na matriz inicialmente criada. A cada criação de thread, é feita a operação em cada linha da matriz pelo vetor completo (considerando o índice em que a thread foi criada), inserindo o resultado então no vetor resultante. Por fim, mostramos o resultado e liberamos a memória. 

## Prints do teste na AWS
![image](https://github.com/MaracujaDoMack/Sistemas-Operacionais-04G/assets/162309148/82d1f6da-2ead-4497-b2b3-de05f19ffe50)

![image](https://github.com/MaracujaDoMack/Sistemas-Operacionais-04G/assets/162309148/22d0c66e-fac7-439a-be2e-d26017377f40)
