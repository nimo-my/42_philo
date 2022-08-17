/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:46:26 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/17 10:08:40 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_info	*make_info_struct(int argc, char *argv[])
{
	t_info *info;

	if (!(argc == 5 || argc == 6))
		return (ERROR);
	info = (t_info *)malloc(sizeof(t_info));
	memset(info, 0, sizeof(t_info));
	if (init_info_argv(argc, argv, info) == RET_ERROR)
		return (ERROR);
	if (setting_struct(info) == RET_ERROR)
		return (ERROR);
	return (info);
}

int	init_info_argv(int argc, char *argv[], t_info *info)
{
	info->num_philo = p_atoi(argv[1]);
	info->time_to_die = p_atoi(argv[2]);
	info->time_to_eat = p_atoi(argv[3]);
	info->time_to_sleep = p_atoi(argv[4]);
	if (argc == 6)
		info->num_must_eat = p_atoi(argv[5]);
	else
		info->num_must_eat = -1;
	if (info->num_philo <= 0 || info->time_to_die <= 0 || \
		info->time_to_eat <= 0 || info->time_to_sleep <= 0 || \
		((argc == 6) && info->num_must_eat <= 0))
	{
		p_error("ERROR : invalid input!\n");
		return (RET_ERROR);
	}
	return (OK);
}

int	setting_struct(t_info *info)
{
	info->philos = malloc(sizeof(t_philo) * info->num_philo);
	info->t_philo = malloc(sizeof(pthread_t) * info->num_philo);
	info->fork = malloc(sizeof(int) * info->num_philo);
	info->m_fork = malloc(sizeof(pthread_mutex_t) * info->num_philo);
	if (!info->philos || !info->t_philo || !info->fork || !info->m_fork)
		return (RET_ERROR); // -1
	pthread_mutex_init(&(info->m_start_time), 0);
	pthread_mutex_init(&(info->m_flag_die), 0);
	pthread_mutex_init(&(info->m_everyone_eat), 0);
	return (OK);
}


int	check_argv(t_info *info)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	
	if (pthread_mutex_init(&(info->m_print), 0)) //thread init
		flag = p_error("ERROR : thread initialize error");
	while (i < info->num_philo)
	{
		info->fork[i] = 1;
		if (pthread_mutex_init(&info->m_fork[i], 0)) //init fork
			flag = p_error("ERROR : mutex initialize error");
		if (flag == RET_ERROR)
			return (RET_ERROR);
		i++;
	}
	if (flag == RET_ERROR)
		return (RET_ERROR);
	return (OK);
}

int	philo_init_input(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		memset(&info->philos[i], 0, sizeof(t_philo));
		info->philos[i].info = (t_info *)malloc(sizeof(t_info));
		if (!info->philos[i].info)
			return (ERROR);
		info->philos[i].info = info;
		info->philos[i].eat_count = 0;
		info->philos[i].id = i;
		info->philos[i].right_fork = i;
		info->philos[i].left_fork = (i + 1) % info->num_philo;
		i++;
	}
	return (OK);
}
