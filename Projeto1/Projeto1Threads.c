#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 10000
#define TRAVEL_TIME 10

// struct para as pessoas que entrarão na escada rolante
typedef struct {
  int timeArrived;
  int personDirection;
} Person;

int waitVector[MAX_CAPACITY]; // vetor das pessoas a esperar
int lastMoment = 0, currentDirection = -1, currentIndex = 0, hasWaited = 0;

// função da thread
void *threadFunction(void *argument) {

  Person *person = (Person *)argument;

  if(currentDirection == -1){ // escada parada
    currentDirection = person->personDirection;
    lastMoment = person->timeArrived + TRAVEL_TIME;
  }
  else if(person->timeArrived < lastMoment && person->personDirection == currentDirection){ // pessoa chegou a tempo e está na mesma direção
    lastMoment = person->timeArrived + TRAVEL_TIME;
  }
  else{
    if(!hasWaited){
      hasWaited = 1;
      waitVector[currentIndex++] = person->timeArrived + TRAVEL_TIME;
    }
    else{
      for(int i = 0; i < currentIndex; i++){
        if(person->timeArrived < waitVector[i]){
          waitVector[i] = person->timeArrived + TRAVEL_TIME;
          return NULL;
        }
      }
      waitVector[currentIndex++] = person->timeArrived + TRAVEL_TIME; // entrará no vetor de espera
    }
  }

  free(person);
  return NULL;
}

int main() {

  int amount = 0;
  pthread_t threadsVector[MAX_CAPACITY];
  Person peopleVector[MAX_CAPACITY];
  FILE *input, *output;

  input = fopen("./input/E_1", "r");
  output = fopen("./output/E_1", "w");
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

  for (int i = 0; i < amount; i++) {
    Person *newPerson = (Person *)malloc(sizeof(Person));
    newPerson->timeArrived = peopleVector[i].timeArrived;
    newPerson->personDirection = peopleVector[i].personDirection;
    pthread_create(&threadsVector[i], NULL, threadFunction, (void *)newPerson); // chamada das threads
  }

  for (int i = 0; i < amount; i++) {
    pthread_join(threadsVector[i], NULL);
  }

  if(hasWaited){
    for(int i = 0; i < currentIndex; i++){
      lastMoment+=10;
    }
  }

  fprintf(output, "Tempo gasto: %d segundos\n", lastMoment);
  fclose(output);
  
  printf("Tempo gasto: %d", lastMoment);
  

  return 0;
}
