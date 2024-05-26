# Projeto 2 - Sistemas Operacionais
## Tranferência de fundos entre duas contas

Neste projeto, desenvolvemos um programa que realiza a transferência de fundos entre duas contas: To (destino) e From (origem). Essa tarefa é implementada declarando as duas contas globalmente e utilizando threads da biblioteca Pthreads do Linux. Cada thread tem acesso às contas através da memória compartilhada e representa uma transferência realizada entre elas. As transferências são feitas de forma concorrente apenas quando há saldo suficiente na conta de envio, permitindo que ocorram mais de uma transferência ao mesmo tempo. Para solucionar a condição de corrida gerada pela solução concorrente, utilizamos um mutex também da biblioteca Pthreads, que impede que mais de uma thread tenha acesso à região crítica de memória (o valor presente na conta de envio), além de não ultrapassar o número máximo de 100 transferências totais. Nosso programa ainda permite que o dinheiro seja enviado da conta To durante a execução, obedecendo às regras impostas anteriormente.

Para realizar os testes, usamos duas abordagens, a primeira ambas as direções de transferência enviam o mesmo valor(100), e na segunda valores diferentes(100 e 0).

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
