/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:21:05 by makamins          #+#    #+#             */
/*   Updated: 2025/04/16 17:21:52 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	safe_print(t_philo *philo, const char *msg)
{
	uint64_t	time;
	int			someone_died;

	time = get_time() - philo->data->start;
	pthread_mutex_lock(&philo->data->lock);
	someone_died = philo->data->someone_died;
	pthread_mutex_unlock(&philo->data->lock);
	if (!someone_died)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%lu %d %s\n", time, philo->philo_id, msg);
		pthread_mutex_unlock(&philo->data->print);
		return ;
	}
	pthread_mutex_lock(&philo->data->print);
	printf("%lu %d %s\n", time, philo->philo_id, msg);
	pthread_mutex_unlock(&philo->data->print);
}

int	error_msg(char *msg)
{
	printf("Error: %s", msg);
	return (1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_atol(const char *nbr)
{
	long	i;
	int		isminus;
	long	res;

	i = 0;
	while (nbr[i] == 32 || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	isminus = 1;
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			isminus *= -1;
		i++;
	}
	res = 0;
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		res = res * 10 + (nbr[i] - '0');
		i++;
	}
	return (res * isminus);
}
