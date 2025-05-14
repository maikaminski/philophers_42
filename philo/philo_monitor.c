/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:05:26 by makamins          #+#    #+#             */
/*   Updated: 2025/04/24 20:05:26 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_philo_death(t_data *data, int i, uint64_t now)
{
	if (now - data->philo[i].last_meal > data->time_to_dead)
	{
		pthread_mutex_lock(&data->lock);
		data->someone_died = true;
		pthread_mutex_unlock(&data->lock);
		safe_print(&data->philo[i], DIE);
		return (1);
	}
	return (0);
}

static int	check_all_philos(t_data *data, uint64_t now)
{
	int	i;

	i = -1;
	while (++i < data->philo_number)
	{
		if (check_philo_death(data, i, now))
			return (1);
	}
	return (0);
}

void	monitor_deaths(t_data *data)
{
	uint64_t	now;

	data->philo->last_meal = get_time();
	while (!data->someone_died)
	{
		now = get_time();
		if (check_all_philos(data, now))
			return ;
		if (all_full(data))
			return ;
		usleep(200);
	}
}

bool	all_full(t_data *data)
{
	int	i;
	int	full_count;

	if (data->num_meals == -1)
		return (false);
	full_count = 0;
	i = 0;
	while (i < data->philo_number)
	{
		pthread_mutex_lock(&data->lock);
		if (data->philo[i].meals_eaten >= data->num_meals)
			full_count++;
		pthread_mutex_unlock(&data->lock);
		i++;
	}
	if (full_count == data->philo_number)
	{
		pthread_mutex_lock(&data->lock);
		data->someone_died = true;
		pthread_mutex_unlock(&data->lock);
		return (true);
	}
	return (false);
}
