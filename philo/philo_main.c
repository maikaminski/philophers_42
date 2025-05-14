/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:23:12 by makamins          #+#    #+#             */
/*   Updated: 2025/04/16 16:59:02 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (error_msg("Invalid number of arguments\n"));
	if (init_data(&data, argc, argv))
		return (1);
	init_mutex(&data);
	init_philos(&data);
	start_dinner(&data);
	monitor_deaths(&data);
	stop_dinner(&data);
	destroy_mutexes(&data);
	free_all(&data);
	return (0);
}
