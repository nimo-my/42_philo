/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 20:10:57 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/15 02:10:14 by jisookim         ###   ########seoul.kr  */
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

int	philo(t_info *info)
{
	if (philo_create_thread(info) == RET_ERROR) // 스레드 생성
		return (RET_ERROR);

	pthread_mutex_lock(&info->m_start_time);
	gettimeofday(&info->start_time, 0);
	pthread_mutex_unlock(&info->m_start_time);

	monitor(info); // 모니터 (계속 돌아갈 수 있도록)

	if (philo_collect_all_thread(info) == RET_ERROR)
		return (RET_ERROR);

	return (OK);
}

int main(int argc, char *argv[])
{
	t_info	*info;

	// [set] & [init]
	info = make_info_struct(argc, argv);
	if (!info || check_argv(argc, info) == RET_ERROR)
	{
		p_error("ERROR : invalid input!\n");
		return (RET_ERROR);
	}
	// [run philo]
	if (philo_init_input(info) == ERROR || philo(info) != OK)
		return (RET_ERROR);

	//[clean_up] , free, thread mutex unlock->destroy
	end_philo(info);

	return (0);
}
