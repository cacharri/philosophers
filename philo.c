/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:29:19 by ialvarez          #+#    #+#             */
/*   Updated: 2022/03/15 20:38:09 by ialvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/time.h>

void *thread_routine(void *arg)
{
	int i = 0;
	int fd;
	int nr_lines = *((int *)arg);

	printf("El hilo comienza a ejecutarse... \n");
	while(i++ < nr_lines)
	{
		fd = open()
	}
}

int main(int argc, char **argv)
{
	pthread_t	thread1;
	int value;

	pthread_create(&thread1, NULL, thread_routine, &value);
	if (argc == 5 || argc == 6)
	{
		if (argc == 5)
		{

		}
	}
	return (0);
}
