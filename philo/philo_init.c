/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:08:22 by makamins          #+#    #+#             */
/*   Updated: 2025/04/16 17:09:50 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, int argc, char **argv)
{
	if (validate_args(argc, argv, data))
		return (1);
	data->someone_died = false;
	data->start = 0;
	data->time_to_think = data->time_to_dead
		- (data->time_to_eat - data->time_to_sleep);
	data->philo = malloc(sizeof(t_philo) * data->philo_number);
	if (!data->philo)
		return (error_msg("Failed to alloc memory for philo.\n"));
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_number);
	if (!data->forks)
	{
		free(data->philo);
		return (error_msg("Failed to alloc memory for forks.\n"));
	}
	return (0);
}

void	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_number)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0
			|| pthread_mutex_init(&data->philo[i].meal_lock, NULL) != 0)
		{
			error_msg("Failed to init mutex.\n");
			return ;
		}
		i++;
	}
	if (pthread_mutex_init(&data->print, NULL) != 0)
	{
		error_msg("Failed to init print mutex.\n");
		return ;
	}
	if (pthread_mutex_init(&data->lock, NULL) != 0)
	{
		error_msg("Failed to init lock mutex.\n");
		return ;
	}
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_number)
	{
		data->philo[i].philo_id = i + 1;
		data->philo[i].meals_eaten = 0;
		data->philo[i].last_meal = 0;
		data->philo[i].left_fork = &data->forks[i];
		data->philo[i].right_fork = &data->forks[(i + 1) % data->philo_number];
		data->philo[i].data = data;
		i++;
	}
}
