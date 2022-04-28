/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:22:51 by ialvarez          #+#    #+#             */
/*   Updated: 2022/04/28 19:22:57 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_ate(t_list *data)
{
	if (pthread_mutex_init(&data->ate, NULL))
	{
		write(1, "There was an error with the init\n", 33);
		exit (1);
	}
}

void	create_thread(t_philo *philo, t_list *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
	{
		if (pthread_create(&data->philo_thread[i], NULL, &thread_routine,
				&philo[i]))
		{
			write(1, "There was an error creating the threads\n", 40);
			exit (1);
		}
		usleep_ph(philo, philo->data->time_die);
	}
}

void	is_ornot_dead(t_philo *philo, t_list *list)
{
	useconds_t	ti;
	int			i;

	i = 0;
	while (philo->times_eat != list->ntpm_eat)
	{
		if (i == list->num_philo - 1)
			i = 0;
		ti = time_me() - philo[i].last_meal_ti;
		if (ti >= philo[i].data->time_die)
		{
			pthread_mutex_lock(&philo->data->ate);
			philo[i].data->dead = 0;
			pthread_mutex_unlock(&philo->data->ate);
			pthread_mutex_unlock(philo[i].forky_l);
			pthread_mutex_unlock(&philo[i].forky_r);
			writting(philo, 5);
			exit (1);
		}
		if (list->num_philo != 1)
			i++;
	}
}

useconds_t	time_me(void)
{
	struct timeval	ti;

	gettimeofday(&ti, NULL);
	return (ti.tv_sec * 1000 + ti.tv_usec / 1000);
}

void	usleep_ph(t_philo *data, useconds_t time)
{
	useconds_t	actual_time;
	useconds_t	interval_time;

	actual_time = time_me();
	interval_time = time + actual_time;
	while (actual_time < interval_time)
	{
		if (data->data->dead == 0)
			break ;
		actual_time = time_me();
		usleep(time);
	}
}
