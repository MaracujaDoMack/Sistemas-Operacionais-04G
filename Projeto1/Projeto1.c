#include <malloc.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define _GNU_SOURCE
#define MAX_CAPACITY 50
#define TRAVEL_TIME 10

typedef struct {
    int timeArrived;
    int personDirection;
} Person;

int lastMoment = 0;
int currentDirection = -1;
sem_t directionSem;

void *threadFunction(void *argument) {
    Person *person = (Person *)argument;
    int finishTime = person->timeArrived + TRAVEL_TIME;

    sem_wait(&directionSem);

    if (currentDirection == -1) {
        currentDirection = person->personDirection;
    }

    if (finishTime > lastMoment && (person->personDirection == currentDirection || currentDirection == -1)) {
        lastMoment = finishTime;
        currentDirection = -1;
    }

    sem_post(&directionSem);

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

    sem_init(&directionSem, 0, 1);

    fscanf(input, "%d", &amount);

    if (amount < 1 || amount > MAX_CAPACITY) {
        printf("Erro! Quantidade de pessoas inválida!\n\n");
        return 1;
    }

    for (int i = 0; i < amount; i++) {
        fscanf(input, "%d %d", &peopleVector[i].timeArrived, &peopleVector[i].personDirection);
    }
    fclose(input);

    currentDirection = peopleVector[0].personDirection;

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

    sem_destroy(&directionSem);

    printf("Programa finalizado!");

    return 0;
}
