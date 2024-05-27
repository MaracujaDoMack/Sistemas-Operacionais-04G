# Projeto 2 - Sistemas Operacionais
## Tranferência de fundos entre duas contas

Desenvolvemos um programa que realiza transferências de fundos entre duas contas, uma de destino (To) e outra de origem (From), utilizando a biblioteca Pthreads do Linux. As contas são declaradas globalmente, e cada thread representa uma transferência, acessando essas contas via memória compartilhada. As transferências ocorrem simultaneamente, desde que haja saldo suficiente na conta de origem, permitindo múltiplas operações ao mesmo tempo.

Para solucionar a condição de corrida provocada pela concorrência, empregamos um mutex da biblioteca Pthreads, garantindo que apenas uma thread acesse a região crítica da memória (saldo da conta de origem) de cada vez. Também estabelecemos um limite máximo de 100 transferências. O programa permite a transferência de fundos da conta de destino (To) durante a execução, seguindo as mesmas regras.

Nos testes, adotamos duas abordagens: na primeira, as transferências em ambas as direções são feitas com o mesmo valor (100); na segunda, os valores transferidos são diferentes (100 e 0).


## Para compilar o programa: 
Instalar o compilador gcc:
```bash
sudo dnf install gcc
```
Compilar o arquivo .c
```bash
gcc exe1.c -o codigo.c
```

## Para executar o programa:
```bash
./exe2.c
```
## Comprovar que os resultados propostos foram alcançados:

### 1) A conta to pode receber mais de uma transferência simultânea;
### 2) A conta from pode enviar mais de uma transferência simultânea;
---------------------
### 3) A conta from não pode enviar dinheiro se não tiver mais saldo;
-------------------
### 4) A conta to pode trocar de ordem com a conta from, ou seja, a conta que enviava pode receber e a conta que recebia pode enviar;
------------------
### 5) Poderão ser realizadas até 100 transações simultâneas de transferência;
----------------
## Execução do programa
### Caso 1: Duas contas transferindo o mesmo valor entre si;
------------
### Caso 2: Conta To enviando todo o dinheiro para From;
------------------------

