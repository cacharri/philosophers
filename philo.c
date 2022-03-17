/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:29:19 by ialvarez          #+#    #+#             */
/*   Updated: 2022/03/17 20:22:24 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/time.h>

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

static void parseo(t_list *data, char **argv, int argc)
{
	if ((data->num_philo = ft_atoi(argv[1])) <= 1)
	{
		write (1, "Philosophers must be more than 1\n", 33);
		exit (1);
	}
	if ((data->time_die = ft_atoi(argv[2])) < 1)
	{
		write (1, "Time to die must be more than 0\n", 32);
		exit (1);
	}
	if ((data->time_eat = ft_atoi(argv[3])) < 1)
	{
		write (1, "Time to eat must be more than 0\n", 32);
		exit (1);
	}
	if ((data->time_sleep = ft_atoi(argv[4])) < 1)
	{
		write (1, "Time to sleep must be more than 0\n", 34);
		exit (1);
	}
	if (argc == 6)
	{
		if ((data->ntpm_eat = ft_atoi(argv[5])) < 1)
		{
			write (1, "Nº of times each philosopher must eat must be more than 0", 58);
			exit (1);
		}
	}
	else
		data->ntpm_eat = -1;
}

void *thread_routine(void *arg)
{
	int i = 0;
	int nr_lines = *((int *)arg);

	printf("El hilo comienza a ejecutarse... \n");
	while(i++ < nr_lines)
	{
		
	}
}

int main(int argc, char **argv)
{
	pthread_t	thread1;
	t_list		data;
	int value;

	pthread_create(&thread1, NULL, thread_routine, &value);
	if (argc == 5 || argc == 6)
	{
		parseo(&data, argv, argc);
		if (argc == 5)
		{

		}
	}
	return (0);
}
