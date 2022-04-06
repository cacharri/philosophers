/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:14:50 by ialvarez          #+#    #+#             */
/*   Updated: 2022/04/06 18:27:12 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/time.h>

typedef enum	e_state
{
	EAT,
	SLEEP,
	THINK,
	RUNNING,
	FINISH
}				t_state;

typedef struct s_list
{
	int					num_philo;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					ntpm_eat;
	int					dead;
	useconds_t			time_all;
	pthread_t			*philo_thread;
	pthread_mutex_t		ate;
	pthread_mutex_t		dead_oppa;
	t_state				state;
}								t_list;


typedef struct s_philo
{
	int					tid;
	int					ate;
	int					times_eat;
	useconds_t			last_meal_ti;
	pthread_mutex_t		forky_l;
	pthread_mutex_t		*forky_r;
	t_list				*data;
}								t_philo;

useconds_t		time_me(void);
void			usleep_ph(t_philo *data, useconds_t time);
void			philos_init(t_philo *philo, t_list *data);
void			*thread_routine(void *arg);
void			routine(t_philo *dock);

#endif
