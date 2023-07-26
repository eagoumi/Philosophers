 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 03:42:43 by eagoumi           #+#    #+#             */
/*   Updated: 2023/07/23 02:26:58 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	grab_fork_left(t_philo *philos)
{
	pthread_mutex_lock(&philos->fork_left);
}

void	grab_fork_right(t_philo *philos)
{
	pthread_mutex_lock(&philos->fork_right);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->fork_left);
	pthread_mutex_unlock(&philo->fork_right);
}

long    current_time(void)
{
    struct timeval gettime;
    long    milli_time;

    gettimeofday(&gettime, NULL);

    /*convert Microseconds to Milliseconds*/
    milli_time = (gettime.tv_sec * 1000) + (gettime.tv_usec / 1000);
    return (milli_time);
}

void    mine_sleep(long time)
{
    long    begin_time;
    long    the_passed_time;

    begin_time = current_time();
    the_passed_time = current_time() + time;

    while (the_passed_time > begin_time)
    {
        usleep(100);
        begin_time = current_time();
    }
}

int if_dead(t_philo *philo)
{
    long    time;
    long    get_time;

    time = current_time() - philo->dernier_repas;
    if (time > philo->args->time_to_die)
    {
        pthread_mutex_lock(&philo->output);
        get_time = (current_time() - philo->args->time_start);
        printf("Philosopher %d is dead at\t %ld", philo->philo_id, get_time);
        philo->are_dead = 1;
        return (1);
    }
    return (0);
}

int check_if_dead(t_alldata *allinfo)
{
// to do
// loop 1
    // loop on every philo : 
        // last time a philo eaten - time now > time to die then 1 down
        // if nb time eat for all philo >= nb time to eat 
    int i;
    int count_nb_of_meals;
    while (1)
    {
        i = 0;
        count_nb_of_meals = 0;
        while (i < allinfo->info->number_philos)
        {
            if (if_dead(&allinfo->philo[i]) == 1)
                return (1);
            count_nb_of_meals += allinfo->philo[i].eaten_time;
            i++;
            if (count_nb_of_meals == 0)
            {
                pthread_mutex_lock(&allinfo->philo->output);
                return (1);
            }
        }
    }
    return (0);
}


void    routine_philos(t_philo *data)
{
    grab_fork_right(data);
    printf("Philosopher %d has taken the RIGHT FORK\n", data->philo_id);
    grab_fork_left(data);
    printf("Philosopher %d has taken the LEFT FORK\n", data->philo_id);
    printf("Philosopher %d is EATING\n", data->philo_id);
    data->dernier_repas = current_time();
    mine_sleep(data->args->time_to_eat);
    release_forks(data);
    data->eaten_time--;
    printf("Philosopher %d is SLEEPING\n", data->philo_id);
    mine_sleep(data->args->time_to_sleep);
    printf("philosopher %d is THINKING\n", data->philo_id);

}

void    *routine_philo_2(void *args)
{
    t_philo *data = (t_philo *)args;
    data->dernier_repas = current_time();
    while (1)
    {
        if(data->eaten_time != 0)
            routine_philos(data);
        else
            break ;
    }
    return NULL;
}
//to_do
/*    
void    *routine(void *data)
{
    t_philo    *philo;

    philo = (t_philo *)data;
    philo->last_meal = current_time();
    while (1)
    {
        if (philo->eat_count != 0)
            routine_2(philo);
        else
            break ;
    }
    return (NULL);
}
*/

// void *philosophers_threads(void *arg)
// {
//     t_philo *data = (t_philo *)arg;

//     while (1)
// 	{
//         printf("Philosopher %d is thinking \n", data->philo_id);
//         mine_sleep(100);
		
// 		grab_fork(data);

//         if ()
//             exit(1);
		
//         printf("Philosopher %d is eating\n", data->philo_id);
//         //if
//         mine_sleep(100);

// 		release_forks(data);
		
//         printf("Philosopher %d is Sleeping\n", data->philo_id);
//         mine_sleep(100);
//     }
//     printf("Philosopher %d has finished eating\n", data->philo_id);
//     return NULL;
// }

void    main_init(int ac, char **av, t_info *get_data)
{
    // Initialize data[i].args members
    get_data->number_philos = atoi(av[1]);
    get_data->time_to_die = atoi(av[2]);
    get_data->time_to_eat = atoi(av[3]);
    get_data->time_to_sleep = atoi(av[4]);
    if (ac == 6)
        get_data->number_ropas = atoi(av[5]);

}

void    init_philo(int number_philos, t_info *get_data, t_alldata *threads, t_philo *data)
{
    int i;
    int j;

    j = 0;
    //info->philo[i].eat_count = info->data->nb_of_meals;
    while (j < 2)
    {
        i = j;
        while (i < number_philos) 
        {
            data[i].philo_id = i;
            data[i].eaten_time = data->args->number_ropas;
            data[i].args = get_data; // Set the pointer to the shared t_info struct
            pthread_create(&threads->philo->threads[i], NULL, routine_philo_2, &data[i]);
            //to_do Protection of pthread_create if the return are not 0
            i += 2;
        }
        if (j == 0)
            mine_sleep(get_data->time_to_eat/2);
        j++;
    }
    i = 0;
    /* Wait for all threads to finish before exiting */
    while (i < number_philos) 
    {
        pthread_join(threads->philo->threads[i], NULL);
        // if (check_if_dead(threads->philo->threads[i]))
        //     exit(1);
        i++;
    }
}

int main(int ac, char **av) 
{
    t_info get_data;
    t_philo *data;
    t_alldata threads;
    int number_philos;
    int i;

    // parsing(ac, av);
    // exit(1);
    if (ac < 5 || ac > 6)
        return 0;
    number_philos = atoi(av[1]);
    // Allocate memory for data and threads arrays
    data = (t_philo *)malloc(sizeof(t_philo) * number_philos);
    // threads = (t_alldata *)malloc(sizeof(t_alldata) * number_philos);
    main_init( ac, av,&get_data);
    /*We have for exemple 1 2 3 4 5 6 7 8 9 10 Philosophers*/
    /*1 while create 1 3 5 7 9 => create one and skip other one */
    init_philo( number_philos, &get_data, &threads, data);
    // printf("sssssss");
    /* Don't forget to free allocated memory before exiting */
    free(data);
    // free(threads.philo->threads);
    return 0;
}

