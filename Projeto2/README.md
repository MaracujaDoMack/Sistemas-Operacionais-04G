# Projeto 2 - Sistemas Operacionais - Transferências entre contas

## Explicação

O projeto consiste em possibilitar a transferência de valores entre duas contas bancarias (TO e FROM), sendo possível realizar 100 transações simultâneas e a troca de quem irá receber e quem irá enviar o valor. Para implementar o sistema, utilizamos dois fluxos de threads para os envios simultâneos entre contas, um deles a conta TO envia e a conta FROM recebe, e no outro a conta FROM envia e a conta TO recebe. Com isso, tivemos que tratar do problema de concorrência e da condição de corrida, criando assim um semáforo, bloquando o acesso a threads, para que quando uma das threads esteja na zona crítica (atualizando o valor de cada conta), outra thread não interfira, mantendo assim a integridade e a confiabilidade dos dados no sistema.

## Para compilar o programa
Instalar o compilador gcc:
```bash
sudo dnf install gcc
```
Compilar o arquivo .c
```bash
gcc codigo.c -o exe1
```
![image](https://github.com/MaracujaDoMack/Sistemas-Operacionais-04G/assets/162309148/158c74a3-0073-4879-b3ce-f1909090f5dd)

## Para executar o programa
```bash
./exe1
```
![image](https://github.com/MaracujaDoMack/Sistemas-Operacionais-04G/assets/162309148/f0d10691-9a76-42e4-8663-b96bad6dbec3)

## Como testar o programa

Compile e execute, seguindo os passos acima.


É possível alterar o valor das variáveis 'valor1' e 'valor2' para que a quantidade de dinheiro nas transferências mude.

'valor1' é o valor que a conta FROM envia para a conta TO (linha 79).

'valor2' é o valor que a conta TO envia para a conta FROM (linha 80).

Por padrão, o valor que colocamos foi de 10 para cada variável.

## Código

![image](https://github.com/MaracujaDoMack/Sistemas-Operacionais-04G/assets/162309148/8f6d5358-911a-4b3b-ada7-f988b3506d06)

![image](https://github.com/MaracujaDoMack/Sistemas-Operacionais-04G/assets/162309148/67551a50-fcd9-4797-a80c-6c3bdd7d6dfc)


## Comprovação dos requisitos:

### 1 - A conta to pode receber mais de uma transferência simultânea

Sim, a conta TO pode receber mais de uma transferência simultânea graças ao uso de threads e semáforos na execução do programa. 

### 2 - A conta from pode enviar mais de uma transferência simultânea

Sim, a conta FROM pode enviar mais de uma transferência simultânea graças ao uso de threads e semáforos na execução do programa.

### Imagem referente aos tópicos 1 e 2:

![image](https://github.com/MaracujaDoMack/Sistemas-Operacionais-04G/assets/162309148/30e7e56a-7203-42c3-a840-2016b1be39a8)

![image](https://github.com/MaracujaDoMack/Sistemas-Operacionais-04G/assets/162309148/5f6aa653-edf7-4ec6-98e9-0ab3ba03c1d3)

![image](https://github.com/MaracujaDoMack/Sistemas-Operacionais-04G/assets/162309148/12e7db9f-d524-44b1-afd9-4acce8846a4c)


---------------------
### 3 -  A conta from não pode enviar dinheiro se não tiver mais saldo

Tanto a conta FROM quanto a conta TO não podem enviar dinheiro caso não tenham o saldo suficiente, o que é verificado dentro das funções que serão executadas pelas threads.

![image](https://github.com/MaracujaDoMack/Sistemas-Operacionais-04G/assets/162309148/d795523b-da47-4564-a2c2-d3a9bae7ebaa)

-------------------
### 4 - A conta to pode trocar de ordem com a conta from, ou seja, a conta que enviava pode receber e a conta que recebia pode enviar

Sim, tanto uma como outra pode enviar dinheiro. Para possibilitar isso, foram criados dois fluxos de threads em um loop, os quais executarão uma das duas funções de transferência (FROM pra TO / TO pra FROM).

![image](https://github.com/MaracujaDoMack/Sistemas-Operacionais-04G/assets/162309148/99ad5859-ae87-4b31-b091-4a55a54ee7a8)

![image](https://github.com/MaracujaDoMack/Sistemas-Operacionais-04G/assets/162309148/a67aff96-f290-408f-adb1-addf0d0307d7)

![image](https://github.com/MaracujaDoMack/Sistemas-Operacionais-04G/assets/162309148/43621431-15de-4882-9150-c4b56a5a2ef2)

------------------
### 5 - Poderão ser realizadas até 100 transações simultâneas de transferência

Sim, é possível realizar 100 transações simultâneas com um loop de 50 iterações, cada uma criando 2 threads.

![image](https://github.com/MaracujaDoMack/Sistemas-Operacionais-04G/assets/162309148/49b1e732-908b-4f38-8bb3-e52f2b6d9ae3)

![image](https://github.com/MaracujaDoMack/Sistemas-Operacionais-04G/assets/162309148/718184e0-27aa-4972-aa43-69f8c01139e9)

------------------

## Teste para saldo insuficiente (Item 3)

Alteramos o valor das variáveis 'valor1' e 'valor2' de 10 para 100 a fim de testar quando há um caso de saldo insuficiente.

![image](https://github.com/MaracujaDoMack/Sistemas-Operacionais-04G/assets/162309148/1277f047-b70c-4d10-b3ae-14cd99130b66)

