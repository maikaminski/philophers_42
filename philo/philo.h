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

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define FORK "has taken a fork"
# define DIE "died"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"

# include <pthread.h>
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
	pthread_t		thread_id;	
    pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
} 	t_philo;

typedef struct s_data
{
	int		*philo_number;
	int		*forks;
	
	uint64_t	time_to_sleep;
	uint64_t	time_to_eat;
	uint64_t	time_to_think;
	uint64_t	time_to_dead;
	uint64_t	start;
	bool	someone_died;
	
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	lock;

	struct s_philo *philo;
	
}	t_data;


#endif