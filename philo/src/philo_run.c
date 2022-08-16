/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:34:46 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/16 21:52:20 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_run(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if ((p->id) % 2 != 0)
		usleep(100);
	if (p->info->num_must_eat)
		philo_day_running(p);
	else
		philo_day_running(p);
	return (NULL);
}

void	philo_day_running(t_philo *p)
{
	int	die;

	while (p->eat_count != p->info->num_must_eat)
	{
		pthread_mutex_lock(&p->info->m_flag_die);
		die = p->info->flag_die;
		pthread_mutex_unlock(&p->info->m_flag_die);
		if (die)
			break ;
		grab_fork(p->info, p);
		philo_eat(p->info, p);
		put_down_fork(p->info, p);
		philo_sleep(p->info, p);
		philo_think(p->info, p);
	}
}

void	philo_eat(t_info *info, t_philo *p)
{
	struct timeval	time;

	voice(EAT, info, p);
	gettimeofday(&time, NULL);
	// pthread_mutex_lock(&p->m_current_eat);
	p->current_eat = time;
	// pthread_mutex_unlock(&p->m_current_eat);
	custom_usleep_timer(&time, info->time_to_eat);
	p->eat_count++; // todo: data race
	if (p->eat_count == info->num_must_eat) // check philo eat all
		voice(EAT_ALL, info, p);
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
