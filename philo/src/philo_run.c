/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:34:46 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/17 14:29:50 by jisookim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_run(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->info->num_philo == 1)
	{
		pthread_mutex_lock(&p->info->m_fork[p->right_fork]);
		p->info->fork[p->right_fork] = 0;
		voice(FORK, p->info, p);
		usleep(p->info->time_to_die);
		pthread_mutex_unlock(&p->info->m_fork[p->right_fork]);
		return (NULL);
	}
	else if ((p->id) % 2 != 0)
		usleep(100);
	philo_day_running(p);
	return (NULL);
}

void	philo_day_running(t_philo *p)
{
	int	die;
	int	eat_all;

	die = 0;
	eat_all = 0;
	while (1)
	{
		pthread_mutex_lock(&p->info->m_flag_die);
		die = p->info->flag_die;
		pthread_mutex_unlock(&p->info->m_flag_die);
		if (die)
			break ;
		grab_fork(p->info, p);
		philo_eat(p->info, p);
		put_down_fork(p->info, p);
		pthread_mutex_lock(&p->m_flag_eat_all);
		eat_all = p->flag_eat_all;
		pthread_mutex_unlock(&p->m_flag_eat_all);
		if (eat_all)
			break ;
		philo_sleep(p->info, p);
		philo_think(p->info, p);

	}
	if (!die)
	{
		pthread_mutex_lock(&p->info->m_everyone_eat);
		p->info->count_everyone_eat++;
		pthread_mutex_unlock(&p->info->m_everyone_eat);
	}
}
