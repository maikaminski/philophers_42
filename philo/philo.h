/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:23:16 by makamins          #+#    #+#             */
/*   Updated: 2025/04/16 16:57:16 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define FORK "has taken a fork"
# define DIE "died"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"

# include <pthread.h>
# include <inttypes.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_philo
{
	int				philo_id;
	int				meals_eaten;
	uint64_t		last_meal;
	pthread_t		thread_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int					philo_number;
	int					num_meals;
	uint64_t			time_to_sleep;
	uint64_t			time_to_eat;
	int64_t				time_to_think;
	uint64_t			time_to_dead;
	uint64_t			start;
	bool				someone_died;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print;
	pthread_mutex_t		lock;
	struct s_philo		*philo;
}	t_data;

// Philo actions
void		take_forks(t_philo *philo);
void		release_forks(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);

// Philo close
void		stop_dinner(t_data *data);
void		destroy_mutexes(t_data *data);
void		free_all(t_data *data);

// Philo init
int			init_data(t_data *data, int argc, char **argv);
void		init_mutex(t_data *data);
void		init_philos(t_data *data);

//Philo monitor
void		monitor_deaths(t_data *data);
bool		all_full(t_data *data);

// Philo routine utils
bool		should_stop(t_philo *philo);
int			is_done_eating(t_philo *philo);
void		handle_single_philo(t_philo *philo);
void		philo_eat(t_philo *philo);

// Philo routine
void		start_dinner(t_data *data);
void		*routine(void *arg);
uint64_t	get_time(void);

// Philo utils
void		safe_print(t_philo *philo, const char *msg);
int			error_msg(char *msg);
int			ft_isdigit(int c);
int			ft_atol(const char *nbr);

// Philo validate
int			is_number(char *str);
int			validate_args(int argc, char **argv, t_data *data);

#endif