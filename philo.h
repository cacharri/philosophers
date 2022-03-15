/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:14:50 by ialvarez          #+#    #+#             */
/*   Updated: 2022/03/15 20:38:07 by ialvarez         ###   ########.fr       */
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

typedef struct s_list
{
	void			*num_philo;
	void			*time_die;
	void			*time_eat;
	void			*time_sleep;
	void			*num_eating;
	struct s_list	*next;
}					t_list;





#endif
