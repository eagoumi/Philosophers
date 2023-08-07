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
// void    init_philo(int number_philos, t_info *get_data, t_alldata *threads, t_philo *data)
// {
//     int i;
//     int j;

//     j = 0;
//     //info->philo[i].eat_count = info->data->nb_of_meals;
//     while (j < 2)
//     {
//         i = j;
//         while (i < number_philos) 
//         {
//             data[i].philo_id = i;
//             data[i].eaten_time = data->args->number_ropas;
//             data[i].args = get_data; // Set the pointer to the shared t_info struct
//             pthread_create(&threads->philo->threads[i], NULL, routine_philo_2, &data[i]);
//             //to_do Protection of pthread_create if the return are not 0
//             i += 2;
//         }
//         if (j == 0)
//             mine_sleep(get_data->time_to_eat/2);
//         j++;
//     }
//     i = 0;
//     /* Wait for all threads to finish before exiting */
//     while (i < number_philos) 
//     {
//         pthread_join(threads->philo->threads[i], NULL);
//         // if (check_if_dead(threads->philo->threads[i]))
//         //     exit(1);
//         i++;
//     }
// }

void    main_init(int ac, char **av, t_info *get_data)
{
    // Initialize data[i].args members

}


int main(int ac, char **av) 
{
    t_alldata get_data;
    t_info data;

    get_data.info = &data;
    if (ac < 5 || ac > 6)
        return 0;
    if (parsing(ac, av))
        return (0);
    get_data
    get_data.info->number_philos = atoi(av[1]);
    printf ("%d\n", get_data.philo->number_philos);
    // get_data.info->time_to_die = atoi(av[2]);
    // get_data.info->time_to_eat = atoi(av[3]);
    // get_data.info->time_to_sleep = atoi(av[4]);
    // get_data.info->number_ropas = -1;
    // get_data.info->is_dead = 0;
    // if (ac == 6)
    //     get_data.info->number_ropas = atoi(av[5]);
    // // main_init(ac, av, &get_data.data);
    // if (initial_mtx(&get_data))
    //     return (0);
    // if (initial_philo(&get_data))
    //     return (0);
    // if (final_philo(&get_data))
    //     return (0);
    
    // // free(data);
    // return 0;
}
