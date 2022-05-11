/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_dead.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:11:30 by ialvarez          #+#    #+#             */
/*   Updated: 2022/05/05 20:22:56 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_max(t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		if (philo[i].times_eat < philo->data->ntpm_eat)
			return (0);
		else if (i == philo->data->num_philo - 1)
			return (1);
		i++;
	}
	return (1);
}

void	aux_deadone(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo[i].data->ate);
	philo[i].data->dead = 0;
	pthread_mutex_unlock(&philo[i].data->ate);
}

void	aux_dead(t_philo *philo, t_list *list, int i)
{
	pthread_mutex_lock(&philo[i].data->ate);
	philo[i].data->dead = 0;
	pthread_mutex_unlock(&philo[i].data->ate);
	if (list->num_philo == 1)
		pthread_mutex_unlock(philo[i].forky_l);
	writting(philo, 5);
}
