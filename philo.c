/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:29:19 by ialvarez          #+#    #+#             */
/*   Updated: 2022/04/27 20:36:32 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	writting(t_philo *dock, int s)
{
	useconds_t	time;

	if (dock->data->dead == 0 && s != DEAD)
		return ;
	time = time_me() - dock->data->startt;
	if (s == 6)
		printf("%d philosopher %d has taken a fork\n", time, dock->tid);
	else if (s == 7)
		printf("%d philosopher %d has taken a fork\n", time, dock->tid);
	else if (s == 1)
		printf ("%d philosopher %d is eating\n", time, dock->tid);
	else if (s == 2 && dock->times_eat != dock->data->ntpm_eat)
		printf ("%d philosopher %d is sleeping\n", time, dock->tid);
	else if (s == 3 && dock->times_eat != dock->data->ntpm_eat)
		printf ("%d philosopher %d is thinking\n", time, dock->tid);
	else if (s == 5)
		printf ("%d philosopher %d have just died\n", time, dock->tid);
}

void	routine(t_philo *dock)
{
	pthread_mutex_lock(&dock->forky_r);
	writting(dock, 7);
	pthread_mutex_lock(dock->forky_l);
	writting(dock, 6);
	writting(dock, 1);
	dock->last_meal_ti = time_me();
	dock->times_eat++;
	usleep_ph(dock, dock->data->time_eat);
	pthread_mutex_unlock(dock->forky_l);
	pthread_mutex_unlock(&dock->forky_r);
	writting(dock, 2);
	usleep_ph(dock, dock->data->time_sleep);
	writting(dock, 3);
}

void	*thread_routine(void *arg)
{
	t_philo	*dock;

	dock = (t_philo *) arg;
	dock->last_meal_ti = time_me();
	pthread_mutex_lock(&dock->data->ate);
	while (dock->data->dead == 1 && dock->times_eat != dock->data->ntpm_eat)
	{
		pthread_mutex_unlock(&dock->data->ate);
		routine(dock);
		pthread_mutex_lock(&dock->data->ate);
	}
	pthread_mutex_unlock(&dock->data->ate);
	return (0);
}

void	init_fork(t_philo *philo, t_list *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_mutex_init(&philo[i].forky_r, NULL))
		{
			write(1, "There was an error with the init\n", 33);
			exit (1);
		}
		else if (i != 0)
			philo[i].forky_l = &philo[i - 1].forky_r;
		else
			philo[0].forky_l = &philo[data->num_philo - 1].forky_r;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list		data;
	t_philo		*philo;
	int			i;

	i = -1;
	philo = NULL;
	if (argc == 5 || argc == 6)
	{
		init(&data, argv);
		parseo(&data, argc);
		mutex_ate(&data);
		philo = malloc(sizeof(t_philo) * data.num_philo);
		philos_init(philo, &data);
		init_fork(philo, &data);
		create_thread(philo, &data);
		is_ornot_dead(philo, &data);
		while (++i < data.num_philo)
			pthread_join(data.philo_thread[i], NULL);
	}
	else
		write(1, "Insert 4 or 5 arguments\n", 24);
	return (0);
}
		/*while (++i <= data.num_philo)
		{
			if (pthread_mutex_init(&philo[i].forky_r, NULL))
			{
				write(1, "There was an error with the init\n", 33);
				return (1);
			}
			else if (i != data.num_philo || i == 0)
				philo[i].forky_l = &philo[i - 1].forky_r;
			else
				philo[0].forky_l = &philo[i].forky_r;
		}
		//philos_init(philo, &data);
		while (++i < data.num_philo)
		{
			if (pthread_create(&data.philo_thread[i], NULL, &thread_routine,
					&philo[i]))
			{
				write(1, "There was an error creating the threads\n", 40);
				return (1);
			}
			usleep(200);
		}*/
