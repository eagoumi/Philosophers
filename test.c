#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
    int philosopher_id;
    pthread_t thread; // pthread_t variable to store the thread ID
    pthread_mutex_t* left_fork;
    pthread_mutex_t* right_fork;
    int times_eaten;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int num_times_to_eat;
} PhilosopherData;

void grab_forks(PhilosopherData* philosopher) {
    pthread_mutex_lock(philosopher->left_fork);
    pthread_mutex_lock(philosopher->right_fork);
}

void release_forks(PhilosopherData* philosopher) {
    pthread_mutex_unlock(philosopher->left_fork);
    pthread_mutex_unlock(philosopher->right_fork);
}

void* philosopher_thread(void* arg) {
    PhilosopherData* data = (PhilosopherData*)arg;

    while (data->times_eaten < data->num_times_to_eat) {
        printf("Philosopher %d is thinking\n", data->philosopher_id);

        usleep(data->time_to_die * 1000000);

        grab_forks(data);

        printf("Philosopher %d is eating (%d times)\n", data->philosopher_id, data->times_eaten + 1);
        usleep(data->time_to_eat * 1000000);

        release_forks(data);

        printf("Philosopher %d is sleeping\n", data->philosopher_id);
        usleep(data->time_to_sleep * 1000000);

        data->times_eaten++;
    }

    printf("Philosopher %d has finished eating and is done\n", data->philosopher_id);
    return NULL;
}

int main() {
    int NUM_PHILOSOPHERS;
    int NUM_TIMES_TO_EAT;

    printf("Enter the number of philosophers: ");
    scanf("%d", &NUM_PHILOSOPHERS);

    printf("Enter the number of times each philosopher must eat: ");
    scanf("%d", &NUM_TIMES_TO_EAT);

    pthread_mutex_t forks[NUM_PHILOSOPHERS];
    PhilosopherData philosopher_data[NUM_PHILOSOPHERS];

    // Initialize forks
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }

    // Set default values for time_to_die, time_to_eat, and time_to_sleep
    int time_to_die = 3;
    int time_to_eat = 2;
    int time_to_sleep = 1;

    // Ask the user for custom time values if provided
    printf("Enter custom values for time_to_die, time_to_eat, and time_to_sleep (in seconds):\n");
    scanf("%d %d %d", &time_to_die, &time_to_eat, &time_to_sleep);

    // Create philosopher threads
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosopher_data[i].philosopher_id = i;
        philosopher_data[i].left_fork = &forks[i];
        philosopher_data[i].right_fork = &forks[(i + 1) % NUM_PHILOSOPHERS];
        philosopher_data[i].times_eaten = 0;
        philosopher_data[i].time_to_die = time_to_die;
        philosopher_data[i].time_to_eat = time_to_eat;
        philosopher_data[i].time_to_sleep = time_to_sleep;
        philosopher_data[i].num_times_to_eat = NUM_TIMES_TO_EAT;

        // Create the thread and store its ID in the philosopher_data struct
        pthread_create(&philosopher_data[i].thread, NULL, philosopher_thread, &philosopher_data[i]);
    }

    // Wait for philosopher threads to finish
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosopher_data[i].thread, NULL);
    }

    // Clean up resources
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}
