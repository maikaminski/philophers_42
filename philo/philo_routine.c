/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:11:54 by makamins          #+#    #+#             */
/*   Updated: 2025/04/16 17:13:00 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_dinner(t_data *data)
{
	int	i;

	data->start = get_time();
	i = 0;
	while (i < data->philo_number)
	{
		data->philo[i].last_meal = data->start;
		if (pthread_create(&data->philo[i].thread_id,
				NULL, routine, &data->philo[i]) != 0)
		{	
			error_msg("Failed to create thread.\n");
			return ;
		}
		i++;
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->philo_number == 1)
	{
		handle_single_philo(philo);
		return (NULL);
	}
	if (philo->philo_id % 2 == 0)
		usleep(philo->data->time_to_eat * 500);
	while (!should_stop(philo))
	{
		if (!is_done_eating(philo))
		{
			philo_eat(philo);
			philo_sleep(philo);
			philo_think(philo);
		}
		else
			usleep(200);
	}
	return (NULL);
}

uint64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
