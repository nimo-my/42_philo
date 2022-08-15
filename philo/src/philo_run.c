/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:34:46 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/15 01:43:23 by jisookim         ###   ########seoul.kr  */
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
		if (!check_philo_dead(p->info, p))
			break ;
		grab_fork(p->info, p);
		if (philo_eat(p->info, p))
			break ;
		put_down_fork(p->info, p);
		philo_sleep(p->info, p);
		philo_think(p->info, p);
	}
	return (NULL);
}

int	check_philo_dead(t_info *info, t_philo *p)
{
	check_curr_time(info);
	if (time_gap(info->start_time, p->current_eat) > info->time_to_die)
	{
		voice(DEAD, info, p);
		info->flag_die = 1;
		return (PHIL_DIE);
	}
	else
	{
		pthread_mutex_unlock(&info->m_start_time);
		return (1);
	}
}

int	philo_eat(t_info *info, t_philo *p)
{
	check_curr_time(info);
	voice(EAT, info, p);
	custom_usleep_timer(info->time_to_eat);
	p->eat_count++;

	if (p->eat_count == info->num_must_eat) // check philo eat all
		voice(EAT_ALL, info, p);
	else if (p->eat_count > info->num_must_eat) // check philo eat all
		voice(EAT_MORE, info, p);
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
