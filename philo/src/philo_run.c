/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:34:46 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/15 23:09:08 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// todo : 시간 측정!

void	*philo_run(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if ((p->id) % 2 != 0)
		usleep(100);
	pthread_mutex_lock(&p->m_current_eat);
	gettimeofday(&p->current_eat, 0);
	pthread_mutex_unlock(&p->m_current_eat);

	while (1)
	{
		if (p->eat_count == -1) // check philo eat all
		{
			break ;
		}
		grab_fork(p->info, p);
		if (philo_eat(p->info, p))
			break ;
		put_down_fork(p->info, p);
		philo_sleep(p->info, p);
		philo_think(p->info, p);
	}
	return (NULL);
}


int	philo_eat(t_info *info, t_philo *p)
{
	pthread_mutex_lock(&p->m_current_eat);
	gettimeofday(&p->current_eat, 0);
	pthread_mutex_unlock(&p->m_current_eat);
	
	voice(EAT, info, p);
	custom_usleep_timer(info->time_to_eat);
	
	p->eat_count++;

	if (p->eat_count == info->num_must_eat) // check philo eat all
	{
		voice(EAT_ALL, info, p);
	}
	
	return (0);
}

void	philo_sleep(t_info *info, t_philo *p)
{
	check_curr_time(info);
	voice(SLEEP, info, p);
	custom_usleep_timer(info->time_to_sleep);
}

void	philo_think(t_info *info, t_philo *p)
{
	check_curr_time(info);
	voice(THINK, info, p);
	usleep(100);
}
