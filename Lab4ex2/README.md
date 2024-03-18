Exercício 2 - Threads


Compilando e rodando o ex2.c


![image](https://github.com/MaracujaDoMack/Sistemas-Operacionais-04G/assets/162309148/51dcde02-6b62-4e46-b917-2abfb904f640)


Documentação:

O código cria uma thread a partir de um processo pai pelo comando clone e passa todas as especificações dessa thread, além do endereço de memória de uma variável 'v' que foi criada no começo da função main e que carrega o valor 3. A variável 'v' será atualizada pela thread criada (terá seu valor incrementado com uma constante de valor 7 com o nome ADD_VALUE), e então o valor modificado será mostrado na função principal (fora da thread).


Resumo: Thread criada recebe uma váriavel com valor 3 e muda seu valor para 10 (somando com 7), e retorna para a função principal com o valor modificado.
