#include "philosophers.h"

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
