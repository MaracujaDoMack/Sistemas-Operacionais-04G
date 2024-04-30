# Lab 04

## Multiplicação Matriz-Vetor usando pthread

O problema sugerido foi o de multiplicação de uma matriz por um vetor utilizando a biblioteca pthread em linguagem C. Para esse problema, primeiramente, nós alocamos a memória para a matriz e o vetor a serem multiplicados, além do vetor resultante, e então criamos um vetor de threads a partir da estrutura pthread, o qual será responsável por guardar todas as threads que criarmos em um for loop, sendo seu tamanho a quantidade de linhas na matriz inicialmente criada. A cada criação de thread, é feita uma operação em cada linha da matriz pelo vetor completo (considerando o índice em que a thread foi criada). A operação consiste em fixar o índice da linha da matriz e multiplicar cada elemento daquela linha pelo seu respectivo elemento do vetor, somar todas essas multiplicações e inserir o resultado na posição atual correta do vetor resultante. Por fim, mostramos o resultado e liberamos a memória. 

## Prints do teste na AWS
![image](https://github.com/MaracujaDoMack/Sistemas-Operacionais-04G/assets/162309148/82d1f6da-2ead-4497-b2b3-de05f19ffe50)

![image](https://github.com/MaracujaDoMack/Sistemas-Operacionais-04G/assets/162309148/22d0c66e-fac7-439a-be2e-d26017377f40)
