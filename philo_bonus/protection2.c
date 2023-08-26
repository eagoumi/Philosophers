#include "philosophers_bonus.h"

int ft_gettimeofday(struct timeval *restrict tp, void *restrict tzp)
{
    int gettime;

    gettime = gettimeofday(tp, tzp);
    if (gettime != 0)
    {
        write(2, "gettimeofday error!\n", 20);
        exit (1);
    }
    return (gettime);
}

int ft_pthread_join(pthread_t thread, void **value_ptr)
{
    int retj;

    retj = pthread_join(thread, value_ptr);
    if (retj != 0)
    {
        write(2, "pthread_join error!\n", 20);
        exit (1);
    }
    return(retj);
}
