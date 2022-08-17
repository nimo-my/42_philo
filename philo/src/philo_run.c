/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:34:46 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/17 10:16:08 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_run(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if ((p->id) % 2 != 0)
		usleep(100);
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
	pthread_mutex_lock(&p->info->m_everyone_eat);
	p->info->count_everyone_eat++;
	pthread_mutex_unlock(&p->info->m_everyone_eat);
}
