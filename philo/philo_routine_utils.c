/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:08:05 by makamins          #+#    #+#             */
/*   Updated: 2025/05/14 14:28:16 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	should_stop(t_philo *philo)
{
	bool	stop;

	pthread_mutex_lock(&philo->data->lock);
	stop = philo->data->someone_died;
	pthread_mutex_unlock(&philo->data->lock);
	return (stop);
}

int	is_done_eating(t_philo *philo)
{
	int	done;

	pthread_mutex_lock(&philo->data->lock);
	done = (philo->data->num_meals > 0 && philo->meals_eaten
			>= philo->data->num_meals);
	pthread_mutex_unlock(&philo->data->lock);
	return (done);
}

void	handle_single_philo(t_philo *philo)
{
	safe_print(philo, FORK);
	usleep(philo->data->time_to_dead * 10);
}

void	philo_eat(t_philo *philo)
{
	uint64_t	start;

	take_forks(philo);
	if (should_stop(philo))
		return ;
	pthread_mutex_lock(&philo->data->lock);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->data->lock);
	safe_print(philo, EAT);
	start = get_time();
	while (!should_stop(philo) && get_time() - start < philo->data->time_to_eat)
		usleep(100);
	release_forks(philo);
	pthread_mutex_lock(&philo->data->lock);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->lock);
}
