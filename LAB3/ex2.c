#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>

// 64kB stack
#define FIBER_STACK (1024 * 64)
// Constante para adicionar no valor criado
#define ADD_VALUE 7 

// The child thread will execute this function
// Executa a thread criada pelo processo pai, atualizando o valor da variavel v em um ponteiro para que seja alterado seu valor fora da Thread tambem
int threadFunction(void* argument) {
    
    int* v = (int*)argument;
    printf("Thread added %d to the value %d\n", ADD_VALUE, *v);
    *v += ADD_VALUE;
    
    return 0;
}

int main() {
    
    void* stack;
    pid_t pid;
    
    // Declaração de uma variavel que vai conter o valor a ser manipulado
    int v = 3;

    printf("Initial value: %d\n", v);

    // Allocate the stack
    stack = malloc(FIBER_STACK);
    if (stack == 0) {
        perror("malloc: could not allocate stack");
        exit(1);
    }

    printf("Creating child thread\n");

    // Call the clone system call to create the child thread
    // É adicionado o endereço de memória da variavel v na função clone para que o mesmo seja enviado para a thread
    pid = clone(&threadFunction, (char*)stack + FIBER_STACK, SIGCHLD | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_VM, &v);
    if (pid == -1) {
        perror("clone");
        exit(2);
    }

    // Wait for the child thread to exit 
    pid = waitpid(pid, NULL, 0);
    if (pid == -1) {
        perror("waitpid");
        exit(3);
    }

    // Free the stack
    free(stack);
    printf( "Child thread returned and stack freed.\n" );
    
     // Mostra o valor atualizado pela Thread
    printf("Final value: %d\n", v);
    
    
    return 0;
}
