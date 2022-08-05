/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:46:26 by jisookim          #+#    #+#             */
/*   Updated: 2022/08/05 12:10:11 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void set_info(t_info *info)
{
	int i;

	i = -1;
	while (++i < info->num_philo)
		pthread_mutex_init(&info->m_fork_arr[i], NULL);
	i = -1;
	while (++i < info->num_philo)
		pthread_mutex_init(&info->m_print_arr[i], NULL);
	// pthread_mutex_init(info->m_fork_arr[i], NULL);
	// 	pthread_mutex_init(info->m_print_arr[i], NULL);
		
}

t_info	*make_info_struct(int argc, char *argv[])
{
	t_info *info;

	info = (t_info *)p_malloc(sizeof(t_info));
	p_memset(info, 0, sizeof(t_info));
	init_info_arr(info);
	set_info(info);
	init_info_input(argc, argv, info);
	return (info);
}

void	init_info_arr(t_info *info)
{
	// permit_fork initialize, default 1.
	info->permit_fork = (int *)p_malloc(sizeof(int) * info->num_philo);
	// p_memset(info->permit_fork, 1, sizeof(int) * info->num_philo);
	info->philos = (t_philo *)p_malloc(sizeof(t_philo) * info->num_philo);
	info->t_id_arr = (pthread_t *)p_double_malloc(sizeof(pthread_t) \
															* info->num_philo);
	info->m_fork_arr = (pthread_mutex_t *)p_double_malloc\
								(sizeof(pthread_mutex_t)* info->num_philo);
	info->m_print_arr = (pthread_mutex_t *)p_double_malloc\
								(sizeof(pthread_mutex_t)* info->num_philo);
}


void	init_info_input(int argc, char *argv[], t_info *info)
{
	int	i;

	i = -1;
	if (argc == 5 || argc == 6)
	{
		info->num_philo = p_atoi(argv[1]);
		info->time_to_die = p_atoi(argv[2]);
		info->time_to_eat = p_atoi(argv[3]);
		info->time_to_sleep = p_atoi(argv[4]);
		// printf("%s %s %s %s \n", argv[1], argv[2], argv[3], argv[4]); // debug
	}
	if (argc == 6)
		info->num_must_eat = p_atoi(argv[5]);
}

int	set_info_and_return(int argc, t_info *info)
{
	if (info->num_philo <= 0 || info->time_to_die <= 0 || \
		info->time_to_eat <= 0 || info->time_to_sleep <= 0)
			return (ERROR);
	if ((argc == 6) && info->num_must_eat <= 0)
			return (ERROR);

	return (OK);
}