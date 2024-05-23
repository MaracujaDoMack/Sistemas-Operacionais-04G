#define _GNU_SOURCE
#include <malloc.h>
#include <sched.h>
#include <semaphore.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define FIBER_STACK 1024 * 64

struct c {
  int saldo;
};

typedef struct c conta;
conta from, to;
int valor;

sem_t mutex;

int transferencia(void arg) {

  sem_wait(&mutex);

  if (from.saldo >= valor) {
    from.saldo -= valor;
    to.saldo += valor;
  }

  printf("Transferência concluída com sucesso!\n");
  printf("Saldo de c1: %d\n", from.saldo);
  printf("Saldo de c2: %d\n\n", to.saldo);

  sem_post(&mutex);

  return 0;
}

int main() {
  voidstack;
  pid_t pids[100];
  int i;

  sem_init(&mutex, 0, 1);

  from.saldo = 100;
  to.saldo = 100;
  valor = 1;

  printf("Transferindo %d para a conta c2\n", valor);

  for (i = 0; i < 100; i++) {
    stack = malloc(FIBER_STACK);
    if (stack == 0) {
      perror("malloc: could not allocate stack");
      exit(1);
    }
    pids[i] =
        clone(&transferencia, (char *)stack + FIBER_STACK, SIGCHLD | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_VM, 0);
    if (pids[i] == -1) {
      perror("clone");
      exit(2);
    }
  }

  for (i = 0; i < 100; i++) {
    waitpid(pids[i], NULL, 0);
    free(stack);
  }

  sem_destroy(&mutex);

  printf("Transferências concluídas e memória liberada.\n");

  return 0;
}
