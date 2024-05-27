![image](https://github.com/MaracujaDoMack/Sistemas-Operacionais-04G/assets/162309148/340cd63b-01d1-4129-a19c-6edc0ca2708f)# Projeto 2 - Sistemas Operacionais - Transferências
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
gcc codigo.c -o exe1
```
![image](https://github.com/MaracujaDoMack/Sistemas-Operacionais-04G/assets/162309148/158c74a3-0073-4879-b3ce-f1909090f5dd)


## Para executar o programa:
```bash
./exe1
```
![image](https://github.com/MaracujaDoMack/Sistemas-Operacionais-04G/assets/162309148/f0d10691-9a76-42e4-8663-b96bad6dbec3)


## Comprovar que os resultados propostos foram alcançados:

### 1 - A conta to pode receber mais de uma transferência simultânea;

Sim, a conta TO pode receber mais de uma transferência simultânea graças ao uso de threads na execução do programa. 

### 2 - A conta from pode enviar mais de uma transferência simultânea;

Sim, a conta FROM pode enviar mais de uma transferência simultânea graças ao uso de threads na execução do programa.

### Imagem referente aos tópicos 1 e 2:

![image](https://github.com/MaracujaDoMack/Sistemas-Operacionais-04G/assets/162309148/30e7e56a-7203-42c3-a840-2016b1be39a8)
![image](https://github.com/MaracujaDoMack/Sistemas-Operacionais-04G/assets/162309148/5f6aa653-edf7-4ec6-98e9-0ab3ba03c1d3)
![image](https://github.com/MaracujaDoMack/Sistemas-Operacionais-04G/assets/162309148/12e7db9f-d524-44b1-afd9-4acce8846a4c)


---------------------
### 3 -  A conta from não pode enviar dinheiro se não tiver mais saldo;

Tanto a conta FROM quanto a conta TO não podem enviar dinheiro caso não tenham o saldo suficiente, o que é verificado dentro das funções que serão executadas pelas threads.

-------------------
### 4 - A conta to pode trocar de ordem com a conta from, ou seja, a conta que enviava pode receber e a conta que recebia pode enviar;

Sim, tanto uma como outra pode enviar dinheiro. Para possibilitar isso, foram criados dois fluxos de threads em um loop, os quais executarão uma das duas funções de transferência (FROM pra TO / TO pra FROM).

------------------
### 5 - Poderão ser realizadas até 100 transações simultâneas de transferência;

Sim, é possível realizar 100 transações simultâneas com um loop de 50 iterações, cada uma criando 2 threads.

----------------
## Execução do programa
### Caso 1: Duas contas transferindo o mesmo valor entre si;
------------
### Caso 2: Conta To enviando todo o dinheiro para From;
------------------------

