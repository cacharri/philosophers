/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:29:19 by ialvarez          #+#    #+#             */
/*   Updated: 2022/03/29 21:11:30 by ialvarez         ###   ########.fr       */
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
			write (1, "Nº of times each philosopher must eat must be more than 0\n", 59);
			exit (1);
		}
	}
}

static void	init(t_list *data, char **argv)
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
}
/*
int lead_mutex(t_list *data)
{
	int	i;

	i = 0;
	while (i++ <= data->num_philo)
	{

	}
}*/
useconds_t		time_me(void)
{
	struct	timeval ti;

	gettimeofday(&ti, NULL);
	return (ti.tv_sec * 1000 + ti.tv_usec / 1000); 
}

void		usleep_ph(t_list *data, useconds_t time)
{
	useconds_t	actual_time;
	useconds_t	interval_time;

	actual_time = time_me();
	interval_time = time + actual_time;
	while (actual_time < interval_time)
	{
		if (data->dead)
			break ;
		actual_time = time_me();
		usleep(interval_time);
	}
}

void	philos_init(t_philo *philo, t_list *data)
{
	int	i;

	i = 0;
	while (i++ <= data->num_philo)
	{
		philo[i].tid = i + 1;
		philo[i].l_fork = i;
		philo[i].r_fork = (i + 1) % data->num_philo;
		philo[i].ate = 0;
		philo[i].times_eat = 0;
		philo[i].data = data;
	}
}

void *thread_routine(void *arg)
{
	t_list	*dock;
	int i;

	i = 0;
	dock = (t_list *) arg;
	dock->time_all = time_me();
	while (dock->dead == 1)
	{
		printf("hola\n");
	}
	
	printf("El hilo comienza a ejecutarse... \n");
	return(0);
}

int main(int argc, char **argv)
{
	t_list		data;
	t_philo		*philo;
	int			i;

	i = 0;
	philo = NULL;
	if (argc == 5 || argc == 6)
	{
		parseo(&data, argv, argc);
		init(&data, argv);
		while (++i <= data.num_philo)
		{
			pthread_create(&data.philo_thread[i], NULL, &thread_routine, &philo[i]);
			printf("as\n");
		}
	}
	else
		write(1, "Insert 4 or 5 arguments\n", 24);
	return (0);
}
