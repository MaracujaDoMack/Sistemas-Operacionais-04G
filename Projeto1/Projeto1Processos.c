#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_CAPACITY 10000
#define TRAVEL_TIME 10

typedef struct {
  int timeArrived;
  int personDirection;
} Person;

Person peopleVector[MAX_CAPACITY];
int waitVector[MAX_CAPACITY];
int currentDirection = -1, amount, lastMoment = 0, currentIndex = 0, hasWaited = 0;

// função que o processo filho vai executar para calcular o tempo total
void process_function(Person *person) {
  
  if (currentDirection == -1) {
    currentDirection = person->personDirection;
    lastMoment = person->timeArrived + TRAVEL_TIME;
  } else if (person->timeArrived < lastMoment && person->personDirection == currentDirection) {
    lastMoment = person->timeArrived + TRAVEL_TIME;
  } else {
    if (!hasWaited) {
      hasWaited = 1;
      waitVector[currentIndex++] = person->timeArrived + TRAVEL_TIME;
    } else {
      for (int i = 0; i < currentIndex; i++) {
        if (person->timeArrived < waitVector[i]) {
          waitVector[i] = person->timeArrived + TRAVEL_TIME;
          return;
        }
      }
      waitVector[currentIndex++] = person->timeArrived + TRAVEL_TIME;
    }
  }
}

int main() {
  printf("Programa iniciado!\n\n");

  FILE *input, *output;

  scanf("%d", &amount);

  for (int i = 0; i < amount; i++) {
    scanf("%d %d", &peopleVector[i].timeArrived, &peopleVector[i].personDirection);
  }

  pid_t pid = fork(); // criação do processo filho

  if (pid == -1) {
    perror("Erro ao criar processo filho!\n\n");
    return 1;
  } else if (pid == 0) {
    printf("Calculando o tempo total!\n\n");

    for (int i = 0; i < amount; i++) {
      process_function(&peopleVector[i]);
    }

    exit(0);
  } 
  else { // processo pai recebe os dados e faz o ultimo cálculo
    wait(NULL);
    if (hasWaited) {
      for (int i = 0; i < currentIndex; i++) {
        lastMoment += TRAVEL_TIME;
      }
    }
    printf("Momento da última pessoa sair: %d\n", lastMoment);
  }

  printf("Programa finalizado!\n\n");

  return 0;
}
