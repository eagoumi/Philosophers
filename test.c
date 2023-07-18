#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define TIME_TO_DIE 3000
#define TIME_TO_EAT 2000
#define TIME_TO_SLEEP 1000
#define NUM_TIMES_TO_EAT 3

typedef enum { THINKING, HUNGRY, EATING, SLEEPING, DEAD } PhilosopherState;

typedef struct {
	PhilosopherState state;
	int timesEaten;
	pthread_mutex_t mutex;
	pthread_cond_t cond;
} Philosopher;

Philosopher philosophers[NUM_PHILOSOPHERS];
pthread_mutex_t forks[NUM_PHILOSOPHERS];

void grab_forks(int philosopher_id) {
	pthread_mutex_lock(&forks[philosopher_id]);
	pthread_mutex_lock(&forks[(philosopher_id + 1) % NUM_PHILOSOPHERS]);
}

void release_forks(int philosopher_id) {
	pthread_mutex_unlock(&forks[philosopher_id]);
	pthread_mutex_unlock(&forks[(philosopher_id + 1) % NUM_PHILOSOPHERS]);
}

void* philosopher_thread(void* arg) {
	int philosopher_id = *(int*)arg;
	Philosopher* philosopher = &philosophers[philosopher_id];

	while (1) {
		printf("Philosopher %d is thinking\n", philosopher_id);

		philosopher->state = THINKING;
		usleep(rand() % TIME_TO_DIE);

		philosopher->state = HUNGRY;
		grab_forks(philosopher_id);

		philosopher->state = EATING;
		philosopher->timesEaten++;
		printf("Philosopher %d is eating (%d times)\n", philosopher_id, philosopher->timesEaten);
		usleep(rand() % TIME_TO_EAT);

		release_forks(philosopher_id);
		philosopher->state = SLEEPING;

		printf("Philosopher %d is sleeping\n", philosopher_id);
		usleep(rand() % TIME_TO_SLEEP);

		if (philosopher->timesEaten == NUM_TIMES_TO_EAT) {
			philosopher->state = DEAD;
			printf("Philosopher %d has finished eating and died\n", philosopher_id);
			break;
		}
	}

	return NULL;
}

int main() {
	pthread_t threads[NUM_PHILOSOPHERS];
	int philosopher_ids[NUM_PHILOSOPHERS];

	// Initialize philosophers and forks
	for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
		philosophers[i].state = THINKING;
		philosophers[i].timesEaten = 0;
		pthread_mutex_init(&philosophers[i].mutex, NULL);
		pthread_cond_init(&philosophers[i].cond, NULL);
		pthread_mutex_init(&forks[i], NULL);
	}

	// Create philosopher threads
	for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
		philosopher_ids[i] = i;
		pthread_create(&threads[i], NULL, philosopher_thread, &philosopher_ids[i]);
	}

	// Wait for philosopher threads to finish
	for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
		pthread_join(threads[i], NULL);
	}

	// Clean up resources
	for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
		pthread_mutex_destroy(&philosophers[i].mutex);
		pthread_cond_destroy(&philosophers[i].cond);
		pthread_mutex_destroy(&forks[i]);
	}

	return 0;
}