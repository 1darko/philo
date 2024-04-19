#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
typedef struct s_settings t_s;

typedef struct s_philo
{
    pthread_t   tr_id;
    int id;
    int eeping;
    int meals;
    int last_meal;
    pthread_mutex_t     *fork_left;
    pthread_mutex_t     *fork_right;
    t_s         *set;
    struct timeval start;
    struct timeval end;

    
} t_philo;

typedef struct s_settings {

    pthread_mutex_t *forks; //A malloc pour nbr philo
    
    t_philo *philo;         //A malloc pour nbr philo
    
    long long start;
    int nbr_philo;          // av[1]
    int time_to_die;        // av[]
    int time_to_eat;        // av[]
    int time_to_sleep;      // av[]
    int glutony;            // av[-1]
    int man_down;           // If philo dead
    pthread_mutex_t eating;
    int num_meals;
    int meals_eaten;
    int dead_philo;
} t_s;


long long true_time(void);
void    true_sleep(int nap_time);
// typedef struct s_global
// {
    
// };




#endif