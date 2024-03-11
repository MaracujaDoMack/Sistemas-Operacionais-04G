#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h> 

#define SIZE 100

int main(){

    pid_t pid;
    int pd[2];

    pipe(pd);

    char text[SIZE];


    pid = fork();
    if(pid < 0){
        printf("Erro ao criar o fork\n");
        return 1;
    }
    else if(pid == 0){
        printf("Processo filho criado!\n");
        close(pd[1]);
        read(pd[0], text, SIZE);
        printf("Mensagem recebida: %s\n", text);
        return 0;
    }
    else{
        printf("Processo pai criado!\n");
        close(pd[0]);
        write(pd[1], "Bom dia\n", 9);
        return 0;
    }

}
