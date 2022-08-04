/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:46:26 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/04 17:08:25 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_info	*make_info_struct(t_info *info)
{
	t_info *info;

	info = (t_info *)p_malloc(sizeof(t_info));
	p_memset(info, 0, sizeof(t_info));
	return (info);
}

t_philo	*make_philo_struct(t_philo *philo)
{
	t_philo *philo;

	philo = (t_philo *)p_malloc(sizeof(t_philo));
	p_memset(philo, 0, sizeof(t_philo));
	return (philo);
}

int	init_info_input(int argc, char *argv[], t_info *info)
{
	if (argc == 5 || argc == 6)
	{
		info->num_of_philo = atoi(argv[1]]);
		info->time_to_die = atoi(argv[2]]);
		info->time_to_eat = atoi(argv[3]]);
		info->time_to_sleep = atoi(argv[4]]);
		p_memset(info->permit_fork, 1, sizeof(num_philo));
	}
	if (argc == 6)
		info->num_must_eat = atoi(argv[5]]);
	}
}

// int	init_philo_input(int argc, char *argv[], t_info *info, t_philo philo)
// {
// 	// 필로 구조체, 포크 번호 구하기 
// 	if ((info->num_of_philo && info->num_of_philo) != 0 || \
// 		 (info->num_of_philo && info->num_of_philo) != 0)
// }

// init
int	set_and_return(int argc, char *argv[], t_info *info, t_philo *philo)
{
	int	flag;
	
	flag = 0;
	if (!(argc == 5 || argc == 6) && (!init_info_input(argc, argv, info, philo)))
		return (ERROR);
	if (flag == ERROR)
		return (ERROR); // 프로그램 종료
	
	// [예외처리] 올바른 인자값인지 확인
	if (info->num_of_philo <= 0 || info->time_to_die <= 0 || \
	info->time_to_eat <= 0 || info->time_to_sleep <= 0)
		return (ERROR);
	if (info->num_must_eat && info->num_must_eat <= 0)
		return (ERROR);

	// permit_fork initialize, default 1.
	info->permit_fork = (int *)p_malloc(sizeof(int) * num_philo);
	p_memset(info->permit_fork, 1, sizeof(int) * num_philo);

	info->tid_arr = (pthread_t *)p_malloc(sizeof(pthread_t) * num_philo);
	p_memset(info->tid_arr, 0, sizeof(pthread_t) * num_philo);

	info->mutex_arr = (p_mutex *)p_malloc(sizeof(p_mutex) * num_philo);
	p_memset(info->mutex_arr, 0, sizeof(p_mutex) * num_philo);

	return (OK);
}