/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:49:51 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/17 21:40:11 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	destroy_info_mutex1(t_info *info)
{
	pthread_mutex_destroy(&info->m_everyone_eat);
	pthread_mutex_destroy(&info->m_must_eat_all_flag);
	pthread_mutex_destroy(&info->m_flag_die);
	pthread_mutex_destroy(&info->m_start_time);
	pthread_mutex_destroy(&info->m_print);
	pthread_mutex_destroy(info->m_fork);
}

void	end_philo(t_info *info)
{
	int	i;

	i = 0;
	destroy_info_mutex1(info);
	while (i < info->num_philo)
	{
		pthread_mutex_destroy(&info->philos[i].m_current_eat);
		pthread_mutex_destroy(&info->philos[i].m_eat_count);
		pthread_mutex_destroy(&info->philos[i].m_flag_eat_all);
		pthread_mutex_destroy(&(info->m_fork[i]));
		free(info->philos[i].info);
		i++;
	}
	free(info->fork);
	free(info->m_fork);
	free(info);
}
