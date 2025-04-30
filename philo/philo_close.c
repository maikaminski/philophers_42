/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:19:45 by makamins          #+#    #+#             */
/*   Updated: 2025/04/16 17:20:37 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	stop_dinner(t_data *data);

void	destroy_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_number)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->print);
		pthread_mutex_destroy(&data->lock);
		i++;
	}
}

void	free_all(t_data *data);