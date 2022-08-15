/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:49:51 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/15 18:50:45 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


void destroy_info_mutex1(t_info *info)
{
	if (pthread_mutex_destroy(&info->m_flag_eat_all))
	{
		pthread_mutex_unlock(&info->m_flag_eat_all);
		pthread_mutex_destroy(&info->m_flag_eat_all);
	}
	if (pthread_mutex_destroy(&info->m_flag_die))
	{
		pthread_mutex_unlock(&info->m_flag_die);
		pthread_mutex_destroy(&info->m_flag_die);
	}
	if (pthread_mutex_destroy(&info->m_start_time))
	{
		pthread_mutex_unlock(&info->m_start_time);
		pthread_mutex_destroy(&info->m_start_time);
	}
}

void destroy_info_mutex2(t_info *info)
{
	int	i;
	i = 0;

	if (pthread_mutex_destroy(&info->m_current_time))
	{
		pthread_mutex_unlock(&info->m_current_time);
		pthread_mutex_destroy(&info->m_current_time);
	}
	if (pthread_mutex_destroy(&info->m_print))
	{
		pthread_mutex_unlock(&info->m_print);
		pthread_mutex_destroy(&info->m_print);
	}
	while (i < info->num_philo)
	{
		if (pthread_mutex_destroy(&(info->m_fork[i])))
		{
			pthread_mutex_unlock(&(info->m_fork[i]));
			pthread_mutex_destroy(&(info->m_fork[i]));
		}
		i++;
	}
}

void	end_philo(t_info *info)
{
	int i;

	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_mutex_destroy(&info->philos[i].m_current_eat))
		{
			pthread_mutex_unlock(&info->philos[i].m_current_eat);
			pthread_mutex_destroy(&info->philos[i].m_current_eat);
		}
		if (pthread_mutex_destroy(&info->philos[i].m_eat_count))
		{
			pthread_mutex_unlock(&info->philos[i].m_eat_count);
			pthread_mutex_destroy(&info->philos[i].m_eat_count);
		}
		free(info->philos[i].info);
		i++;
	}
	destroy_info_mutex1(info);
	destroy_info_mutex2(info);

	free(info->philos);
	free(info->fork);
	free(info->m_fork);

	free(info);
}
