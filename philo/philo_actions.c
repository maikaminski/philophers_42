/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:43:27 by makamins          #+#    #+#             */
/*   Updated: 2025/04/15 18:44:11 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		if (!should_stop(philo))
			safe_print(philo, FORK);
		pthread_mutex_lock(philo->left_fork);
		if (!should_stop(philo))
			safe_print(philo, FORK);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		if (!should_stop(philo))
			safe_print(philo, FORK);
		pthread_mutex_lock(philo->right_fork);
		if (!should_stop(philo))
			safe_print(philo, FORK);
	}
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	philo_sleep(t_philo *philo)
{
	uint64_t	start;

	if (should_stop(philo))
	{
		release_forks(philo);
		return ;
	}
	start = get_time();
	safe_print(philo, SLEEP);
	usleep(philo->data->time_to_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	uint64_t	start;
	int			time_to_think;

	if (should_stop(philo))
	{
		release_forks(philo);
		return ;
	}
	start = get_time();
	safe_print(philo, THINK);
	if (philo->data->time_to_think > 10)
		time_to_think = 10;
	else if (philo->data->time_to_think <= 0)
		time_to_think = 0;
	else
		time_to_think = philo->data->time_to_think;
	usleep(time_to_think * 1000);
}
