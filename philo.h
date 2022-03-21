/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:14:50 by ialvarez          #+#    #+#             */
/*   Updated: 2022/03/21 20:31:13 by ialvarez         ###   ########.fr       */
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

typedef struct s_philo
{
	int					tid;
	int					ate;
	int					l_fork;
	int					r_fork;
	p_thread_t			thread_tid;
}								t_philo;

typedef struct s_list
{
	int					num_philo;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					num_eating;
	int					ntpm_eat;
	pthread_mutex_t		ate;
	pthread_mutex_t		*forks;
	pthread_mutex_t		write_to;
	pthread_mutex_t		*philoss;
	t_philo				*philo;
}								t_list;





#endif
