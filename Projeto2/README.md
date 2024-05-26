# Projeto 2 - Sistemas Operacionais
## Tranferência de fundos entre duas contas

Desenvolvemos um programa que realiza transferências de fundos entre duas contas, uma de destino (To) e outra de origem (From), utilizando a biblioteca Pthreads do Linux. As contas são declaradas globalmente, e cada thread representa uma transferência, acessando essas contas via memória compartilhada. As transferências ocorrem simultaneamente, desde que haja saldo suficiente na conta de origem, permitindo múltiplas operações ao mesmo tempo.

Para solucionar a condição de corrida provocada pela concorrência, empregamos um mutex da biblioteca Pthreads, garantindo que apenas uma thread acesse a região crítica da memória (saldo da conta de origem) de cada vez. Também estabelecemos um limite máximo de 100 transferências. O programa permite a transferência de fundos da conta de destino (To) durante a execução, seguindo as mesmas regras.

Nos testes, adotamos duas abordagens: na primeira, as transferências em ambas as direções são feitas com o mesmo valor (100); na segunda, os valores transferidos são diferentes (100 e 0).


## Para compilar o programa: 
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
