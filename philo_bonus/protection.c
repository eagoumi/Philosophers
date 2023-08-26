#include "philosophers_bonus.h"

void *ft_malloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		write(2, "Malloc ERROR\n", 13);
		exit (1);
	}
	return (ptr);
}

int ft_pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg)
{
    int ret;

    ret = pthread_create(thread, attr, start_routine, arg);
    if (ret != 0)
    {
        write(2, "pthread_create error!\n", 22);
        exit (1);
    }
    return(ret);
}


int ft_sem_wait(sem_t *sem)
{
    int semw;

    semw = sem_wait(sem);
    if (semw != 0)
    {
        write(2, "sem_wait error!\n", 16);
        exit (1);
    }
    return (semw);
}

int ft_sem_post(sem_t *sem)
{
    int semp;

    semp = sem_post(sem);
    if (semp != 0)
    {
        write(2, "sem_post error!\n", 16);
        exit (1);
    }
    return (semp);
}