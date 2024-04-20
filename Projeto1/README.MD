# Projeto escada rolante

## Objetivo:

Esse projeto consiste em criar um sistema que gerencie o movimento de uma escada rolante dupla. Caso uma pessoa queira entrar na escada rolante, ela deixará de estar parada e se movimentará na direção que a pessoa quer ir. Caso haja mais pessoas querendo ir para a mesma direção, contanto que o tempo de sua chegada seja menor que o tempo de chegada da ultima pessoa + 10 (tempo de levar uma pessoa de uma extremidade a outra), ela poderá entrar na escada também. Caso contrário ou se a pessoa estiver na outra extremidade, terá que esperar o tempo final e ai poderá entrar na escada, indo para a direação oposta.

## Como compilar o código

Primeiramente é necessário instalar o compilador gcc com o comando:

sudo dnf install gcc

Depois é necessario compilar os arquivos com o comando:

gcc -o [nome_do executavel] [nome_do_arquivo]

gcc -o proj Projeto1Processos.c

gcc -o proj Projeto1Threads.c

O ultimo passo seria executar o programa:

./[nome_do_executavel]

./proj


Todas os testes e seus respectivos resultados propostos estão em formato .txt para serem testados (input e output)!

## Resolvendo por THREADS

### Estratégia: 
 Adotamos a estratégia de criar um vetor para as threads que utilizariamos e cada vez chamariamos a função da thread e o sistema esperaria a execução de cada uma pelo comando join, não atropelando e causando problemas. Na função que executa as threads, fazemos primeiramente a verificação se a escada está parada (currentDirection = -1), se estiver parada ela recebera as informações da primeira pessoa que quiser entrar na escada rolante, caso a escada esteja em movimento verificamos se a próxima pessoa que chegou conseguirá subir na escada (direção terá que ser a da escada atual e o tempo de chegada da pessoa precisa atender ao intervalo ao qual a escada começou). Caso nenhuma dessas verificações forem válidas, significa que, ou a próxima pessoa está na direção oposta a qual a escada está indo, ou não conseguiu chegar a tempo mesmo estando na mesma direção da escada. Nesse último caso, as o valor de chegada das pessoas são gravados em um novo vetor, chamado waitVector, que guardará o valor justamente para acumular em um único índice todas as pessoas que vão entrar na escada ao mesmo tempo, no final são somados a cada indice 10 unidades para a variável que guarda o valor do tempo total.

## Exemplos de Inputs e Outputs com THREADS

TIRA O PRINT DA EXECUÇÃO DE ALGUNS INPUTS E OUTPUTS GUSTAVÃO

## Resolvendo por PROCESSOS

### Estratégia: 
 A ideia para resolver o problema usando processos foi parecida com a de threads. Primeiramente construímos a estrutura de processos com o fork e a criação do processo filho a partir do processo pai, então construímos uma função para que o processo filho execute e calcule o valor inicial do tempo final, então esse valor será recebido pelo processo pai a fim de calcular os valores que faltam (valores no vetor de espera) e escrever no arquivo de saída.

## Exemplos de Inputs e Outputs com PROCESSOS

TIRA O PRINT DA EXECUÇÃO DE ALGUNS INPUTS E OUTPUTS GUSTAVÃO
