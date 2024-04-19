#include "philo.h"

long long true_time(void)
{
	struct timeval	clock;

    gettimeofday(&clock, NULL);
    return ((clock.tv_sec / 1000) + (clock.tv_usec * 1000));
}

void    true_sleep(int nap_time)
{
    long long clock;
    long long post_nap;

    clock = true_time();
    post_nap = clock;
    while(post_nap - clock < nap_time)
    {
        usleep(nap_time / 10);
        post_nap = true_time();
    }
}