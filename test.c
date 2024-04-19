
#include "philo.h"

// void *eep_time(void *arg)
// {
//     t_philo *ph = (t_philo *)arg;
//     long long time;
//     gettimeofday(&ph->end, NULL);
//     time = ph->end.tv_usec - ph->start.tv_usec;
//     printf("%lld %d is sleeping\n", time ,ph->id);
//     usleep(200);
//     return 0;
// }
// void    *bla(void *arg)
// {   
//     t_philo *ph = (t_philo *)arg;
//     long long time;
//     if(ph->set->dead_philo == 1)
//         exit(1);
//     pthread_mutex_lock(ph->fork_left);
//     pthread_mutex_lock(ph->fork_right);
//     gettimeofday(&ph->end, NULL);
//     // printf("INSIDE : %ld\n", &ph->set.start.tv_usec);
//     time = ph->end.tv_usec - ph->start.tv_usec;
//     printf("%lld %d is eating\n", time ,ph->id);
//     usleep(200);
//     pthread_mutex_unlock(ph->fork_right);
//     pthread_mutex_unlock(ph->fork_left);
//     gettimeofday(&ph->end, NULL);
//     time = ph->end.tv_usec - ph->start.tv_usec;
//     printf("%lld %d is sleeping\n", time,ph->id);
//     usleep(200);
//     gettimeofday(&ph->end, NULL);
//     time = ph->end.tv_usec - ph->start.tv_usec;
//     printf("%lld %d is thinking\n", time, ph->id);

//     // printf("%d done eeping\n", ph->id);
//     return 0;
// }


// int main()
// {
//     int i = 0;
//     t_s settings;
//     settings.dead_philo = 0;
//     gettimeofday(&settings.start, NULL);
//     settings.philo = malloc(sizeof(t_philo) * 10);
//     for(; i < 10; i++)
//         settings.philo[i].id = i + 1; 

//     settings.forks = malloc(sizeof(pthread_mutex_t) * 10);
//     for(i = 0; i < 10; i++)
//     {
//         pthread_mutex_init(&(settings.forks[i]), NULL);
//         settings.philo[i].fork_right = &settings.forks[i];
//     }
//     for(i = 0; i < 10; i++)
//         settings.philo[i].fork_left = &settings.forks[(i + 1) %10];
//     i = 0;
//     while(1)
//     {   
//         settings.philo[i].set = &settings;
//         pthread_create(&(settings.philo[i].tr_id), NULL, &bla, &settings.philo[i]);
//         // pthread_join(settings.philo[i].tr_id, NULL);
//         pthread_detach((settings.philo[i].tr_id));
//         i++;
//             if(i == 10)
//                 i = 0;
//     }
//     // i = 0;
//     // while(1)
//     // {
//     //     if(i == 10)
//     //         i = 0;
//     //     pthread_create(&(settings.philo[i].tr_id), NULL, &bla, &settings.philo[i]);
//     //     pthread_join(settings.philo[i].tr_id, NULL);
//     //     i++;

//     // }

//     return 0;
// }

void    *bla(void *arg)
{   
    t_philo *ph = (t_philo *)arg;
	t_s *set = ph->set;
    long long local_time;
    if(ph->set->dead_philo == 1)
        exit(1);
    pthread_mutex_lock(ph->fork_left);
    pthread_mutex_lock(ph->fork_right);
    // printf("INSIDE : %ld\n", &ph->set.start.tv_usec);
    local_time = true_time();
    // printf("Le start est a %lld\n", set->start);
    // printf("Local est a %lld\n", local_time);

    printf("%lld %d is eating\n", local_time - set->start ,ph->id);
    true_sleep(200);
    pthread_mutex_unlock(ph->fork_right);
    pthread_mutex_unlock(ph->fork_left);
    local_time = true_time();
    printf("%lld %d is sleeping\n", local_time - set->start,ph->id);
    true_sleep(200);
    local_time = true_time();
    printf("%lld %d is thinking\n", local_time - set->start , ph->id);

    // printf("%d done eeping\n", ph->id);
    return 0;
}


int main()
{
    int i = 0;
    t_s settings;
    settings.dead_philo = 0;
    settings.start = true_time();
    printf("Le start est a %lld ICI  et la cest %lld\n", settings.start, true_time());

    settings.philo = malloc(sizeof(t_philo) * 10);
    for(; i < 10; i++)
        settings.philo[i].id = i + 1; 

    settings.forks = malloc(sizeof(pthread_mutex_t) * 10);
    for(i = 0; i < 10; i++)
    {
        pthread_mutex_init(&(settings.forks[i]), NULL);
        settings.philo[i].fork_right = &settings.forks[i];
    }
    for(i = 0; i < 10; i++)
        settings.philo[i].fork_left = &settings.forks[(i + 1) %10];
    i = 0;
    for(; i < 10; i++)
    {   
        settings.philo[i].set = &settings;
        pthread_create(&(settings.philo[i].tr_id), NULL, &bla, &settings.philo[i]);
        // pthread_join(settings.philo[i].tr_id, NULL);
        // pthread_detach((settings.philo[i].tr_id));
    }
    i = 0;
    while(1)
    {
        pthread_join(settings.philo[i].tr_id, NULL);
        i++;
        if (i == 9)
            i = 0;
    }

    // i = 0;
    // while(1)
    // {
    //     if(i == 10)
    //         i = 0;
    //     pthread_create(&(settings.philo[i].tr_id), NULL, &bla, &settings.philo[i]);
    //     pthread_join(settings.philo[i].tr_id, NULL);
    //     i++;

    // }

    return 0;
}