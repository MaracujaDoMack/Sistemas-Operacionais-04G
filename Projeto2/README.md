# Projeto 2 - Sistemas Operacionais
## Tranferência de fundos entre duas contas

Neste projeto, desenvolvemos um programa para transferir fundos entre duas contas: uma conta destino (To) e uma conta origem (From). A implementação utiliza a biblioteca Pthreads do Linux, declarando as contas globalmente. Cada thread, representando uma transferência, acessa essas contas via memória compartilhada. As transferências ocorrem simultaneamente, desde que haja saldo suficiente na conta de origem, permitindo múltiplas operações ao mesmo tempo.

Para resolver a condição de corrida gerada pela execução concorrente, utilizamos um mutex da biblioteca Pthreads. Isso garante que apenas uma thread acesse a região crítica da memória (o saldo da conta de origem) por vez. Também limitamos o número máximo de transferências a 100. Além disso, o programa permite a transferência de fundos da conta destino (To) durante a execução, obedecendo às mesmas regras.

Para testar o programa, utilizamos duas abordagens: na primeira, ambas as transferências enviam o mesmo valor (100); na segunda, os valores transferidos são diferentes (100 e 0).

## Para compilar o programa: 
Instalamos o editor vim:
```bash
sudo dnf install vim
```
Abrimos e editamos os programas com o vim:
```bash
vim proj2.c
```
Instalamos o compilador gcc:
```bash
sudo dnf install gcc
```
E então compilamos o arquivo .c
```bash
gcc proj2.c -o projeto2
```

## Para executar o programa:
```bash
./projeto2
```
## Comprovar que os resultados propostos foram alcançados:

### 1) A conta to pode receber mais de uma transferência simultânea;
### 2) A conta from pode enviar mais de uma transferência simultânea;
