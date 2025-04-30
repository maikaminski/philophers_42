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
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_philo
{
	int				philo_id; // id do philosopho
	int				meals_eaten; //contador de refeições
	uint64_t		last_meal; // tempo de quando foi a ultima refeição
	pthread_t		thread_id;	// id da thread
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int					philo_number; //numero de philosophos
	int					num_meals; // número de refeições (caso seja passado como parametro)
	uint64_t			time_to_sleep;
	uint64_t			time_to_eat;
	uint64_t			time_to_think;
	uint64_t			time_to_dead;
	uint64_t			start; //quando começa
	bool				someone_died;
	pthread_mutex_t		*forks; // trava o garfo
	pthread_mutex_t		print; // trava o write
	pthread_mutex_t		lock; // controle de morte
	struct s_philo		*philo;
}	t_data;

int	ft_atol(const char *nbr);
int	error_msg(char *msg);
int	validate_args(int argc, char **argv, t_data *data);

#endif