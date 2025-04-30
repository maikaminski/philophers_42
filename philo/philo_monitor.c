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

void	monitor_deaths(t_data *data);

void	has_died(int philo);

void	all_full(t_data *data); //só se for passado o número minimo de refeições para cada