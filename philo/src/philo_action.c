/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:00:25 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/17 10:12:48 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	grab_fork(t_info *info, t_philo *p)
{
	if (p->id % 2)
	{
		pthread_mutex_lock(&info->m_fork[p->left_fork]);
		info->fork[p->left_fork] = 0;
		voice(FORK, info, p);
		pthread_mutex_lock(&info->m_fork[p->right_fork]);
		info->fork[p->right_fork] = 0;
		voice(FORK, info, p);
	}
	else
	{
		pthread_mutex_lock(&info->m_fork[p->right_fork]);
		info->fork[p->right_fork] = 0;
		voice(FORK, info, p);
		pthread_mutex_lock(&info->m_fork[p->left_fork]);
		info->fork[p->left_fork] = 0;
		voice(FORK, info, p);
	}
}

void	philo_eat(t_info *info, t_philo *p)
{
	struct timeval	time;

	voice(EAT, info, p);
	gettimeofday(&time, NULL);
	p->current_eat = time;
	custom_usleep_timer(&time, info->time_to_eat);
	pthread_mutex_lock(&p->m_eat_count);
	p->eat_count++;
	pthread_mutex_unlock(&p->m_eat_count);
	
}

void	put_down_fork(t_info *info, t_philo *p)
{
	info->fork[p->right_fork] = 1;
	info->fork[p->left_fork] = 1;
	pthread_mutex_unlock(&info->m_fork[p->right_fork]);
	pthread_mutex_unlock(&info->m_fork[p->left_fork]);
}

void	philo_sleep(t_info *info, t_philo *p)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	voice(SLEEP, info, p);
	custom_usleep_timer(&time, info->time_to_sleep);
}

void	philo_think(t_info *info, t_philo *p)
{
	voice(THINK, info, p);
	usleep(100);
}
