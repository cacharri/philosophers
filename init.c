/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:09:10 by ialvarez          #+#    #+#             */
/*   Updated: 2022/05/04 21:50:41 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	mas;

	mas = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			mas = -mas;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (res * mas > 214748364 && str[i] - '0' > 7)
			return (-1);
		if (res * mas < -214748364 && str[i] - '0' >= 8)
			return (0);
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * mas);
}

int	parseo(t_list *data, int argc)
{
	if (data->num_philo < 1)
		write (1, "Philosophers must be more than 0\n", 33);
	if (data->time_die < 1)
		write (1, "Time to die must be more than 0\n", 32);
	if (data->time_eat < 1)
		write (1, "Time to eat must be more than 0\n", 32);
	if (data->time_sleep < 1)
		write (1, "Time to sleep must be more than 0\n", 34);
	if (argc == 6)
	{
		if (data->ntpm_eat < 1)
		{
			write (1, "Each philosopher must eat  more times than 0\n", 45);
			return (0);
		}
	}
	if (data->num_philo < 1 || data->time_die < 1 || data->time_eat < 1
		|| data->time_sleep < 1)
		return (0);
	return (1);
}

void	init(t_list *data, char **argv)
{
	data->num_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->dead = 1;
	data->philo_thread = malloc(sizeof(pthread_t) * data->num_philo);
	if (argv[5])
		data->ntpm_eat = ft_atoi(argv[5]);
	else
		data->ntpm_eat = -1;
	data->startt = time_me();
}

void	philos_init(t_philo *philo, t_list *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
	{
		philo[i].tid = i + 1;
		philo[i].times_eat = 0;
		philo[i].data = data;
		philo[i].last_meal_ti = time_me();
	}
}
