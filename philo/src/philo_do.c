/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_do.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:34:46 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/08 11:00:17 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"



int philo_eat(t_philo *philo, long *start_time, long *end_time)
{
	*start_time = set_time(philo->go_info->start_time);
	usleep(philo->go_info->time_to_eat);
	*end_time = set_time(philo->go_info->end_time);
	printf("\033[0;35m[%ld] [%d] philo is eating!\n\033[0m", *end_time - *start_time, philo->id);
				
	philo->check_start = *end_time;
	philo->eat_time = *end_time - *start_time;

	// return fork
	pthread_mutex_unlock(&(philo->go_info->m_fork_arr[philo->left_fork]));
	pthread_mutex_unlock(&(philo->go_info->m_fork_arr[philo->right_fork]));
	philo->eat_count++;
	usleep(100);

	return (OK);
}

int	philo_sleep(t_philo *philo, long *start_time, long *end_time)
{
	*start_time = set_time(philo->go_info->start_time);
	usleep(philo->go_info->time_to_eat);
	*end_time = set_time(philo->go_info->end_time);
	printf("\033[0;32m[%ld] [%d] philo is sleeping...\n\033[0m", *end_time - *start_time, philo->id);

	//if (*end_time-*start_time > philo->go_info->time_to_sleep)
	return (OK);
}