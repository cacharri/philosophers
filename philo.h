/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:14:50 by ialvarez          #+#    #+#             */
/*   Updated: 2022/05/05 20:28:02 by ialvarez         ###   ########.fr       */
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

# define EAT 1
# define SLEEP 2
# define THINK 3
# define RUNNING 4
# define DEAD 5
# define FORLEF 6
# define FORIGH 7

typedef struct s_list
{
	int					num_philo;
	useconds_t			time_die;
	useconds_t			time_eat;
	useconds_t			time_sleep;
	int					ntpm_eat;
	int					dead;
	useconds_t			startt;
	pthread_t			*philo_thread;
	pthread_mutex_t		ate;
}								t_list;

typedef struct s_philo
{
	int					tid;
	int					times_eat;
	useconds_t			last_meal_ti;
	pthread_mutex_t		*forky_l;
	pthread_mutex_t		forky_r;
	t_list				*data;
}								t_philo;

useconds_t		time_me(void);
void			usleep_ph(t_philo *data, useconds_t time);
void			philos_init(t_philo *philo, t_list *data);
void			*thread_routine(void *arg);
void			routine(t_philo *dock);
void			writting(t_philo *dock, int s);
int				parseo(t_list *data, int argc);
void			init(t_list *data, char **argv);
int				is_ornot_dead(t_philo *philo, t_list *list);
void			init_fork(t_philo *philo, t_list *data);
int				create_thread(t_philo *philo, t_list *list);
int				check_max(t_philo *philo);
void			aux_deadone(t_philo *philo, int i);
void			aux_dead(t_philo *philo, t_list *list, int i);

#endif
