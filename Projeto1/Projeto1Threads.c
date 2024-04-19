#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 10000
#define TRAVEL_TIME 10

typedef struct {
  int timeArrived;
  int personDirection;
} Person;

int lastMoment = 0;
int currentDirection = -1;
pthread_mutex_t lock;

void *threadFunction(void *argument) {

  Person *person = (Person *)argument;
  int arrivalTime = person->timeArrived;
  int direction = person->personDirection;

  pthread_mutex_lock(&lock);

  if (lastMoment == 0 && currentDirection == -1) {
    currentDirection = direction;
    lastMoment = arrivalTime + TRAVEL_TIME;
  }

  if (arrivalTime < lastMoment && direction == currentDirection) {
    lastMoment = arrivalTime + TRAVEL_TIME;
  } else {
    // alguma função que espera
    lastMoment += TRAVEL_TIME;
  }

  pthread_mutex_unlock(&lock);

  free(person);
  return NULL;
}

int main() {
  printf("Programa iniciado!\n\n");

  int amount = 0;
  pthread_t threadsVector[MAX_CAPACITY];
  Person peopleVector[MAX_CAPACITY];
  FILE *input, *output;

  input = fopen("input.txt", "r");
  output = fopen("output.txt", "w");
  if (input == NULL || output == NULL) {
    printf("Erro! Arquivos não foram abertos corretamente!\n\n");
    return 1;
  }

  fscanf(input, "%d", &amount);

  if (amount < 1 || amount > MAX_CAPACITY) {
    printf("Erro! Quantidade de pessoas inválida!\n\n");
    return 1;
  }

  for (int i = 0; i < amount; i++) {
    fscanf(input, "%d %d", &peopleVector[i].timeArrived, &peopleVector[i].personDirection);
  }
  fclose(input);

  pthread_mutex_init(&lock, NULL);

  for (int i = 0; i < amount; i++) {
    Person *newPerson = (Person *)malloc(sizeof(Person));
    newPerson->timeArrived = peopleVector[i].timeArrived;
    newPerson->personDirection = peopleVector[i].personDirection;
    pthread_create(&threadsVector[i], NULL, threadFunction, (void *)newPerson);
  }

  for (int i = 0; i < amount; i++) {
    pthread_join(threadsVector[i], NULL);
  }

  fprintf(output, "Tempo gasto: %d segundos\n", lastMoment);
  fclose(output);

  pthread_mutex_destroy(&lock);

  printf("Programa finalizado!");

  return 0;
}
